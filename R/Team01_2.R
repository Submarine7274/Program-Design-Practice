myfun<-function(n,k){
  library(plyr)
  first_letters<-c('A','B','C','E','F','G','H','K','L','M','P','Q')
  letters_to_code<-c(A=23, B=13, C=28, E=27, F=39, G=25, H=18, K=34, L=19, M=22, P=21, Q=26, W=16, Z=20)
  lookup_value<-c(W="16", Z="20", "0"="0", "1"="1", "2"="2", "3"="3", "4"="4", "5"="5", "6"="6", "7"="7", "8"="8", "9"="9")
  verify_Y_value<-function(Y_value){
    return(ifelse(Y_value %%7 ==0,"Y","N"))
  }
  calculate_Y_value<-function(n_factor){
    return (as.numeric(n_factor[1:11]%*%c(1, 1:9 ,1)))
  }
  calculate_Z_value<-function(m_factor){
    return(as.numeric(floor((m_factor[1:11]%*%c(6,4,1,5,4,2,1,2,3,3,5)/17))))
  }
  built_id_string<-function(first_letter,w_index,z_index,digits){
    last_7_id <-character(7)
    last_7_id[w_index]<-'W'
    last_7_id[z_index]<-'Z'
    last_7_id[last_7_id ==""] <-digits
    return (paste0(c(first_letter,last_7_id), collapse = ""))
  }
  built_n_array<-function(id,first_letter){
    chars <- strsplit(substr(id, 2, 8), "")[[1]]
    mapped_chars <- lookup_value[chars]
    n_string<- paste0(as.numeric(letters_to_code[first_letter]),paste0(mapped_chars,collapse = ""))
    return (as.numeric(strsplit(n_string, "")[[1]]))
  }
  find_wz_position<-function(w_index,z_index){
    w_start<-w_index +2 +(z_index < w_index)
    z_start<-z_index +2 +(w_index < z_index)
    w_end <- w_start +1
    z_end <- z_start +1
    return(c(w_start,w_end,z_start,z_end))
  }
  built_m_array<-function(n_array,locked_positions){
    sort_idx <- setdiff(1:11, locked_positions)
    m_array <- n_array
    m_array[sort_idx] <- sort(n_array[sort_idx])
    return(m_array)
  }
  clean_unuse_columns<- function(df){
    df$w_z_index <- NULL
    df$digit1 <- NULL
    df$digit2 <- NULL
    df$digit3 <- NULL
    df$digit4 <- NULL
    df$digit5 <- NULL
    return(df)
  }
  position_domain<- expand.grid(W=1:7, Z=1:7)
  valid_w_z_positions<-position_domain[abs(position_domain$W - position_domain$Z) >1, ]
  df_input <- data.frame(
    first_letter = sample(first_letters,n,replace =  TRUE),
    w_z_index =sample(1:nrow(valid_w_z_positions),n,replace = TRUE),
    digit1 = sample(0:9,n,replace = TRUE),
    digit2 = sample(0:9,n,replace = TRUE),
    digit3 = sample(0:9,n,replace = TRUE),
    digit4 = sample(0:9,n,replace = TRUE),
    digit5 = sample(0:9,n,replace = TRUE),
    stringsAsFactors = FALSE
  )
  results <- adply(df_input ,.margins = 1,function(row){
    id_first_letter<-row$first_letter
    w_index<-valid_w_z_positions$W[row$w_z_index]
    z_index <- valid_w_z_positions$Z[row$w_z_index]
    digits <- as.character(c(row$digit1, row$digit2, row$digit3, row$digit4, row$digit5))
    id_string<-built_id_string(id_first_letter, w_index, z_index, digits)
    n_array<-built_n_array(id_string, id_first_letter)
    locked_positions<-find_wz_position(w_index, z_index)
    m_array<- built_m_array(n_array, locked_positions)
    Y_value  <- calculate_Y_value(n_array)
    Z_value  <- calculate_Z_value(m_array)
    Y_or_N <- verify_Y_value(Y_value)
    Group  <- (Y_value + Z_value) %% k
    return(data.frame(
      ID = id_string, 
      YValue = Y_value, 
      YorN = Y_or_N, 
      ZValue = Z_value, 
      Group = Group, 
      first_letter = id_first_letter,                            
      digits_sequence = paste0(digits, collapse=""),
      stringsAsFactors = FALSE
    ))
  },.expand = FALSE, .id = NULL)
  results <- clean_unuse_columns(results)
  sorted_index <- order(
    results$first_letter,
    results$YorN == "N", 
    -results$ZValue,
    results$digits_sequence
  )
  results <- results[sorted_index, ]
  dashed_line <- paste0(rep("-", 45), collapse = "")
  cat(sprintf("%-14s%7s%6s%8s%7s", "ID", "YValue", "YorN", "ZValue", "Group"), sep="\n")
  cat(dashed_line, sep="\n")
  data_lines <- sprintf("%-12s %6d %6s %6d %6d", 
                        results$ID, results$YValue, results$YorN, results$ZValue, results$Group)
  cat(data_lines, sep="\n")
  cat(dashed_line, sep="\n")
  correct_count <- length(which(results$YorN == "Y"))
  correct_rate <- round(100 * correct_count / n, 1)
  cat(sprintf("Total ID: %d      Correct ID: %d (%.1f%%)\n\n", n, correct_count, correct_rate))
  group_stats <- ddply(results, "Group", function(g_data) {
    data.frame(
      total_id = nrow(g_data),
      count_y = length(which(g_data$YorN == "Y")),
      count_n = length(which(g_data$YorN == "N")),
      letters_string = paste0(sort(unique(g_data$first_letter)), collapse=","),
      stringsAsFactors = FALSE
    )
  })
  valid_groups <- group_stats[group_stats$total_id >= 5, ]
  if (nrow(valid_groups) > 0) {
    valid_groups <- valid_groups[order(valid_groups$Group), ]
    out_lines <- sprintf("Group %d: %2d IDs   %dY%dN  %s",
                         valid_groups$Group, valid_groups$total_id,
                         valid_groups$count_y, valid_groups$count_n, valid_groups$letters_string)
    cat(out_lines, sep="\n")
  }
}