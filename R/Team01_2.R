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
  calculate_X_value<-function(m_factor){
    return(as.numeric(floor((m_factor[1:11]%*%c(6,4,1,5,4,2,1,2,3,3,5)/17))))
  }
  built_id_string<-function(first_letter,w_index,z_index,digits){
    last_7_id <-character(7)
    last_7_id[w_index]<-'W'
    last_7_id[z_index]<-'Z'
    last_7_id[char ==""] <-digits
    return (paste0(c(first_letter,last_7_id), collapse = ""))
  }
  built_n_array<-function(id,first_letter){
    chars <- strsplit(substr(s, 2, 8), "")[[1]]
    mapped_chars <- lookup_value[chars]
    n_string<- paste0(as.numeric(letters_to_code[first_letter]),paste0(mapped_chars,collapse = ""))
    return (as.numeric(strsplit(n_string, "")[[1]]))
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
  results <- adply(df_input ,.margins = 1)
}