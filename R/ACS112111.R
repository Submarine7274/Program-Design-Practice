myfun<-function(filename){
  calculate_difficulty<-function(high_rank_rate,low_rank_rate){
    return {(high_rank_rate+low_rank_rate)/2}
  }
  calculate_discrimnation<-function(high_rank_rate,low_rank_rate){
    return {high_rank_rate-low_rank_rate}
  }
  calculate_score_bins<-function(scores){
    bins<-numeric(6)
    bins[1] <- length(which(scores >= 40 & scores <= 49))
    bins[2] <- length(which(scores >= 50 & scores <= 59))
    bins[3] <- length(which(scores >= 60 & scores <= 69))
    bins[4] <- length(which(scores >= 70 & scores <= 79))
    bins[5] <- length(which(scores >= 80 & scores <= 89))
    bins[6] <- length(which(scores >= 90 & scores <= 100))
    return {bins}
  }
  calculate_class_counts <- function(df, col_class) {
    counts <- ddply(df, col_class, function(d) {
      data.frame(count = nrow(d), stringsAsFactors = FALSE)
    })
    return {counts[order(counts[, 1]), ]}
  }
  calculate_top8_of_all<- function(df_sorted,)
  library(plyr)
  anslist <- read.table(filename, header = TRUE, sep = ',', stringsAsFactors = FALSE)
  question_names<-c("E1","E2","E3","E4","E5","M1","M2","Q1","Q2","Q3")
  correct_answers<-c("B","D","A","C","B","15","20","Rose","Lavender","Jasmine")
  score_weight<-c(rep(3,5),rep(10,2),rep(7,3))
  base_score<-44
  column_class <- 
}
myfun <- function(filename) {
  library(plyr)
  
  # ==========================================
  # [模組化輔助函式區] 
  # ==========================================
  
  calc_class_counts <- function(df, col_class) {
    counts <- ddply(df, col_class, function(d) {
      data.frame(count = nrow(d), stringsAsFactors = FALSE)
    })
    counts[order(counts[, 1]), ] 
  }
  
  calc_score_bins <- function(scores) {
    bins <- numeric(6)
    bins[1] <- length(which(scores >= 40 & scores <= 49))
    bins[2] <- length(which(scores >= 50 & scores <= 59))
    bins[3] <- length(which(scores >= 60 & scores <= 69))
    bins[4] <- length(which(scores >= 70 & scores <= 79))
    bins[5] <- length(which(scores >= 80 & scores <= 89))
    bins[6] <- length(which(scores >= 90 & scores <= 100))
    bins
  }
  
  calc_top_8_overall <- function(df_sorted, col_id) {
    df_sorted[which(df_sorted$rank_min <= 8), col_id]
  }
  
  # [更新] 使用 d_ply 直接印出各班前三名
  print_top_3_by_class <- function(df_sorted, col_class, col_id, class_names, num_classes) {
    if (num_classes %% 2 != 0) {
      target_classes <- class_names[seq(2, num_classes, by=2)] 
    } else {
      target_classes <- class_names[seq(1, num_classes, by=2)] 
    }
    
    top3_df <- df_sorted[which((df_sorted[, col_class] %in% target_classes) & (df_sorted$class_rank <= 3)), ]
    if (nrow(top3_df) > 0) {
      # d_ply: 只做事，不回傳資料
      d_ply(top3_df, col_class, function(d) {
        d <- d[order(-d$Score, d[, col_id]), ]
        cat(sprintf("Class %s Top 3: %s\n", d[1, col_class], paste(d[, col_id], collapse=" ")))
      })
      cat("\n") # 補空行
    }
  }
  
  calc_class_avg <- function(df, col_class) {
    c_avg <- ddply(df, col_class, function(d) {
      n_c <- nrow(d)
      avg <- as.numeric((d$Score %*% rep(1, n_c)) / n_c)
      data.frame(avg = avg, stringsAsFactors = FALSE)
    })
    c_avg[order(c_avg[, 1]), ]
  }
  
  calc_question_accuracy <- function(nc_mat, n_tot) {
    as.numeric((rep(1, n_tot) %*% nc_mat) / n_tot) * 100
  }
  
  calc_high_low_groups <- function(rank_avg, n_tot) {
    list(
      high_idx = which(rank_avg / n_tot <= 0.25),
      low_idx  = which(rank_avg / n_tot >= 0.75)
    )
  }
  
  calc_group_accuracy <- function(nc_mat, group_idx) {
    n_grp <- length(group_idx)
    if (n_grp == 0) return(rep(0, ncol(nc_mat)))
    as.numeric((rep(1, n_grp) %*% nc_mat[group_idx, ]) / n_grp)
  }
  
  calc_item_difficulty <- function(high_rate, low_rate) {
    (high_rate + low_rate) / 2
  }
  
  calc_item_discrimination <- function(high_rate, low_rate) {
    high_rate - low_rate
  }
  
  # ==========================================
  # [主程式區 - 資料準備與算分]
  # ==========================================
  anslist <- read.table(filename, header = TRUE, sep = ',', stringsAsFactors = FALSE)
  col_class <- names(anslist)[1]
  col_id <- names(anslist)[2]
  N <- nrow(anslist)
  
  q_names <- c("E1", "E2", "E3", "E4", "E5", "M1", "M2", "Q1", "Q2", "Q3")
  ans_key <- c("B", "D", "A", "C", "B", "15", "20", "Rose", "Lavender", "Jasmine")
  scores_w <- c(3, 3, 3, 3, 3, 10, 10, 7, 7, 7)
  base_score <- 44
  
  ans_matrix <- as.matrix(anslist[, 3:12])
  key_matrix <- matrix(rep(ans_key, each = N), nrow = N, ncol = 10)
  num_correct_mat <- (ans_matrix == key_matrix) * 1 
  
  anslist$Score <- as.numeric(num_correct_mat %*% scores_w) + base_score
  anslist$rank_min <- rank(-anslist$Score, ties.method = 'min')
  anslist$rank_avg <- rank(-anslist$Score, ties.method = 'average')
  
  anslist <- ddply(anslist, col_class, function(df) {
    df$class_rank <- rank(-df$Score, ties.method = 'min')
    df
  })
  anslist_sorted <- anslist[order(-anslist$Score, anslist[, col_class], anslist[, col_id]), ]
  
  # ==========================================
  # [主程式區 - 呼叫小函式取得數據]
  # ==========================================
  class_counts_df <- calc_class_counts(anslist, col_class)
  class_names <- class_counts_df[, 1]
  num_classes <- length(class_names)
  
  bin_counts     <- calc_score_bins(anslist$Score)
  top8_ids       <- calc_top_8_overall(anslist_sorted, col_id)
  class_avg_df   <- calc_class_avg(anslist, col_class)
  overall_avg    <- as.numeric((anslist$Score %*% rep(1, N)) / N)
  
  q_acc_rate     <- calc_question_accuracy(num_correct_mat, N)
  hl_groups      <- calc_high_low_groups(anslist$rank_avg, N)
  
  n_high         <- length(hl_groups$high_idx)
  n_low          <- length(hl_groups$low_idx)
  high_acc_rate  <- calc_group_accuracy(num_correct_mat, hl_groups$high_idx)
  low_acc_rate   <- calc_group_accuracy(num_correct_mat, hl_groups$low_idx)
  
  item_diff      <- calc_item_difficulty(high_acc_rate, low_acc_rate)
  item_disc      <- calc_item_discrimination(high_acc_rate, low_acc_rate)
  
  # ==========================================
  # [格式化輸出區]
  # ==========================================
  line_len_1 <- 9 + 5 * num_classes + 6
  
  # (1) 班級人數 (水平輸出，只能用 paste0)
  cat(sprintf("%-9s", "Class:"), paste0(sprintf("%5s", class_names), collapse=""), sprintf("%6s", "Total"), "\n", sep="")
  cat(paste0(rep("-", line_len_1), collapse=""), "\n", sep="")
  cat(sprintf("%-9s", "Student:"), paste0(sprintf("%5d", class_counts_df$count), collapse=""), sprintf("%6d", N), "\n\n", sep="")
  
  # (2) 分數區間
  bin_names <- c("40-49", "50-59", "60-69", "70-79", "80-89", "90-100")
  cat(sprintf("%-9s", "Score:"), paste0(sprintf("%6s", bin_names), collapse=""), "\n", sep="")
  cat(paste0(rep("-", 52), collapse=""), "\n", sep="")
  cat(sprintf("%-9s", "Student:"), paste0(sprintf("%6d", bin_counts), collapse=""), "\n\n", sep="")
  
  # (3 & 4) Top 8 與 Top 3 (呼叫 d_ply 函式)
  cat("All Top 8: ", paste(top8_ids, collapse=" "), "\n\n", sep="")
  print_top_3_by_class(anslist_sorted, col_class, col_id, class_names, num_classes)
  
  # (5) 平均分數
  cat(sprintf("%-9s", "Class:"), paste0(sprintf("%5s", class_names), collapse=""), sprintf("%6s", "All"), "\n", sep="")
  cat(paste0(rep("-", line_len_1), collapse=""), "\n", sep="")
  cat(sprintf("%-9s", "Avg:"), paste0(sprintf("%5.1f", class_avg_df$avg), collapse=""), sprintf("%6.1f", overall_avg), "\n\n", sep="")
  
  # (6) 正確率
  cat(sprintf("%-14s", "Question:"), paste0(sprintf("%5s", q_names), collapse=""), "\n", sep="")
  cat(paste0(rep("-", 62), collapse=""), "\n", sep="")
  cat(sprintf("%-14s", "Correct(%):"), paste0(sprintf("%5.0f", round(q_acc_rate, 0)), collapse=""), "\n\n", sep="")
  
  # (7) 高低分群、難度與鑑別度
  cat(sprintf("Top-scoring group: %d    Lowest-scoring group: %d\n\n", n_high, n_low))
  cat(sprintf("%-18s", "Question:"), paste0(sprintf("%5s", q_names), collapse=""), "\n", sep="")
  cat(paste0(rep("-", 75), collapse=""), "\n", sep="")
  cat(sprintf("%-18s", "Difficulty:"), paste0(sprintf("%5.2f", item_diff), collapse=""), "\n", sep="")
  cat(sprintf("%-18s", "Discrimination:"), paste0(sprintf("%5.2f", item_disc), collapse=""), "\n", sep="")
}
