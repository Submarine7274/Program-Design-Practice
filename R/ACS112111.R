myfun <- function(filename) {
  library(plyr)
  calculate_difficulty <- function(high_rank_rate, low_rank_rate) {
    (high_rank_rate + low_rank_rate) / 2
  }
  calculate_discrimination <- function(high_rank_rate, low_rank_rate) {
    high_rank_rate - low_rank_rate
  }
  calculate_score_bins <- function(student_scores) {
    score_bins <- numeric(6)
    score_bins[1] <- length(which(student_scores >= 40 & student_scores <= 49))
    score_bins[2] <- length(which(student_scores >= 50 & student_scores <= 59))
    score_bins[3] <- length(which(student_scores >= 60 & student_scores <= 69))
    score_bins[4] <- length(which(student_scores >= 70 & student_scores <= 79))
    score_bins[5] <- length(which(student_scores >= 80 & student_scores <= 89))
    score_bins[6] <- length(which(student_scores >= 90 & student_scores <= 100))
    score_bins
  }
  calculate_class_counts <- function(data_frame, column_class) {
    class_counts <- ddply(data_frame, column_class, function(subset_data_frame) {
      data.frame(count = nrow(subset_data_frame), stringsAsFactors = FALSE)
    })
    class_counts[order(class_counts[, 1]), ]
  }
  calculate_top_eight_overall <- function(sorted_data_frame, column_student_id) {
    sorted_data_frame[which(sorted_data_frame$minimum_rank <= 8), column_student_id]
  }
  calculate_class_averages <- function(data_frame, column_class) {
    class_averages <- ddply(data_frame, column_class, function(subset_data_frame) {
      number_of_students <- nrow(subset_data_frame)
      average_score <- as.numeric((subset_data_frame$Score %*% rep(1, number_of_students)) / number_of_students)
      data.frame(average_score = average_score, stringsAsFactors = FALSE)
    })
    class_averages[order(class_averages[, 1]), ]
  }
  calculate_question_accuracy <- function(binary_correct_matrix, total_students) {
    as.numeric((rep(1, total_students) %*% binary_correct_matrix) / total_students) * 100
  }
  calculate_high_low_score_groups <- function(average_rank, total_students) {
    list(
      high_score_indices = which(average_rank / total_students <= 0.25),
      low_score_indices  = which(average_rank / total_students >= 0.75)
    )
  }
  calculate_group_accuracy <- function(binary_correct_matrix, group_indices) {
    number_in_group <- length(group_indices)
    if (number_in_group == 0) return(rep(0, ncol(binary_correct_matrix)))
    as.numeric((rep(1, number_in_group) %*% binary_correct_matrix[group_indices, ]) / number_in_group)
  }
  print_class_counts <- function(class_names, student_counts, total_students, dynamic_line_length) {
    cat(sprintf("%-9s", "Class:"), paste0(sprintf("%5s", class_names), collapse=""), sprintf("%6s", "Total"), "\n", sep="")
    cat(paste0(rep("-", dynamic_line_length), collapse=""), "\n", sep="")
    cat(sprintf("%-9s", "Student:"), paste0(sprintf("%5d", student_counts), collapse=""), sprintf("%6d", total_students), "\n\n", sep="")
  }
  print_score_bins <- function(score_bin_counts) {
    score_bin_names <- c("40-49", "50-59", "60-69", "70-79", "80-89", "90-100")
    cat(sprintf("%-9s", "Score:"), paste0(sprintf("%6s", score_bin_names), collapse=""), "\n", sep="")
    cat(paste0(rep("-", 52), collapse=""), "\n", sep="")
    cat(sprintf("%-9s", "Student:"), paste0(sprintf("%6d", score_bin_counts), collapse=""), "\n\n", sep="")
  }
  print_top_eight_overall <- function(top_eight_student_ids) {
    cat("All Top 8: ", paste(top_eight_student_ids, collapse=" "), "\n\n", sep="")
  }
  print_top_three_by_class <- function(sorted_data_frame, column_class, column_student_id, class_names, number_of_classes) {
    if (number_of_classes %% 2 != 0) {
      target_classes <- class_names[seq(2, number_of_classes, by=2)]
    } else {
      target_classes <- class_names[seq(1, number_of_classes, by=2)]
    }
    
    top_three_data_frame <- sorted_data_frame[which((sorted_data_frame[, column_class] %in% target_classes) & (sorted_data_frame$class_rank <= 3)), ]
    
    if (nrow(top_three_data_frame) > 0) {
      d_ply(top_three_data_frame, column_class, function(subset_data_frame) {
        subset_data_frame <- subset_data_frame[order(-subset_data_frame$Score, subset_data_frame[, column_student_id]), ]
        cat(sprintf("Class %s Top 3: %s\n", subset_data_frame[1, column_class], paste(subset_data_frame[, column_student_id], collapse=" ")))
      })
      cat("\n")
    }
  }
  print_class_averages <- function(class_names, class_averages, overall_average, dynamic_line_length) {
    cat(sprintf("%-9s", "Class:"), paste0(sprintf("%5s", class_names), collapse=""), sprintf("%6s", "All"), "\n", sep="")
    cat(paste0(rep("-", dynamic_line_length), collapse=""), "\n", sep="")
    cat(sprintf("%-9s", "Avg:"), paste0(sprintf("%5.1f", class_averages), collapse=""), sprintf("%6.1f", overall_average), "\n\n", sep="")
  }
  print_question_accuracy <- function(question_names, question_accuracy_rates) {
    cat(sprintf("%-14s", "Question:"), paste0(sprintf("%5s", question_names), collapse=""), "\n", sep="")
    cat(paste0(rep("-", 62), collapse=""), "\n", sep="")
    cat(sprintf("%-14s", "Correct(%):"), paste0(sprintf("%5.0f", round(question_accuracy_rates, 0)), collapse=""), "\n\n", sep="")
  }
  print_item_statistics <- function(number_of_high_scores, number_of_low_scores, question_names, item_difficulty, item_discrimination) {
    cat(sprintf("Top-scoring group: %d    Lowest-scoring group: %d\n\n", number_of_high_scores, number_of_low_scores))
    cat(sprintf("%-18s", "Question:"), paste0(sprintf("%5s", question_names), collapse=""), "\n", sep="")
    cat(paste0(rep("-", 75), collapse=""), "\n", sep="")
    cat(sprintf("%-18s", "Difficulty:"), paste0(sprintf("%5.2f", item_difficulty), collapse=""), "\n", sep="")
    cat(sprintf("%-18s", "Discrimination:"), paste0(sprintf("%5.2f", item_discrimination), collapse=""), "\n", sep="")
  }
  student_answers_data_frame <- read.table(filename, header = TRUE, sep = ',', stringsAsFactors = FALSE)
  column_class <- names(student_answers_data_frame)[1]
  column_student_id <- names(student_answers_data_frame)[2]
  total_students <- nrow(student_answers_data_frame)
  question_names <- c("E1", "E2", "E3", "E4", "E5", "M1", "M2", "Q1", "Q2", "Q3")
  correct_answer_key <- c("B", "D", "A", "C", "B", "15", "20", "Rose", "Lavender", "Jasmine")
  question_score_weights <- c(3, 3, 3, 3, 3, 10, 10, 7, 7, 7)
  base_score <- 44
  student_answers_matrix <- as.matrix(student_answers_data_frame[, 3:12])
  reference_key_matrix <- matrix(rep(correct_answer_key, each = total_students), nrow = total_students, ncol = 10)
  binary_correct_matrix <- (student_answers_matrix == reference_key_matrix) * 1
  student_answers_data_frame$Score <- as.numeric(binary_correct_matrix %*% question_score_weights) + base_score
  student_answers_data_frame$minimum_rank <- rank(-student_answers_data_frame$Score, ties.method = 'min')
  student_answers_data_frame$average_rank <- rank(-student_answers_data_frame$Score, ties.method = 'average')
  student_answers_data_frame <- ddply(student_answers_data_frame, column_class, function(subset_data_frame) {
    subset_data_frame$class_rank <- rank(-subset_data_frame$Score, ties.method = 'min')
    subset_data_frame
  })
  sorted_answers_data_frame <- student_answers_data_frame[order(-student_answers_data_frame$Score, student_answers_data_frame[, column_class], student_answers_data_frame[, column_student_id]), ]
  class_counts_data_frame <- calculate_class_counts(student_answers_data_frame, column_class)
  class_names <- class_counts_data_frame[, 1]
  number_of_classes <- length(class_names)
  score_bin_counts <- calculate_score_bins(student_answers_data_frame$Score)
  top_eight_student_ids <- calculate_top_eight_overall(sorted_answers_data_frame, column_student_id)
  class_averages_data_frame <- calculate_class_averages(student_answers_data_frame, column_class)
  overall_average <- as.numeric((student_answers_data_frame$Score %*% rep(1, total_students)) / total_students)
  question_accuracy_rates <- calculate_question_accuracy(binary_correct_matrix, total_students)
  high_and_low_score_groups <- calculate_high_low_score_groups(student_answers_data_frame$average_rank, total_students)
  number_of_high_scores <- length(high_and_low_score_groups$high_score_indices)
  number_of_low_scores <- length(high_and_low_score_groups$low_score_indices)
  high_group_accuracy_rates <- calculate_group_accuracy(binary_correct_matrix, high_and_low_score_groups$high_score_indices)
  low_group_accuracy_rates <- calculate_group_accuracy(binary_correct_matrix, high_and_low_score_groups$low_score_indices)
  item_difficulty <- calculate_difficulty(high_group_accuracy_rates, low_group_accuracy_rates)
  item_discrimination <- calculate_discrimination(high_group_accuracy_rates, low_group_accuracy_rates)
  dynamic_line_length <- 9 + 5 * number_of_classes + 6
  print_class_counts(class_names, class_counts_data_frame$count, total_students, dynamic_line_length)
  print_score_bins(score_bin_counts)
  print_top_eight_overall(top_eight_student_ids)
  print_top_three_by_class(sorted_answers_data_frame, column_class, column_student_id, class_names, number_of_classes)
  print_class_averages(class_names, class_averages_data_frame$average_score, overall_average, dynamic_line_length)
  print_question_accuracy(question_names, question_accuracy_rates)
  print_item_statistics(number_of_high_scores, number_of_low_scores, question_names, item_difficulty, item_discrimination)
}