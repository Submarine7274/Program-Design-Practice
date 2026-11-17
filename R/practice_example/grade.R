# ==========================================
# grade.R (助教批改專用腳本)
# ==========================================

source("env.R", encoding = "UTF-8")

get_standard_answer <- function(df) {
  df$Job <- ifelse(is.na(df$Job), "Normal", trimws(df$Job))
  df$Economy <- ifelse(is.na(df$Economy), "Normal", trimws(df$Economy))
  
  base_prices <- c(Sword=10, Shield=50, Armor=100, Lance=5, Dagger=5, Axe=15, 
                   Mace=15, Stave=15, Bow=30, Elixir=10, Ring=5, Amulets=5, Belt=3, Grimoire=5)
  base_vals <- unname(base_prices[df$Category])
  
  true_tiers <- df$ClaimedTier
  for(i in 1:nrow(df)) {
    if (df$ClaimedTier[i] == "Unique") {
      valid <- unique_items_list[[df$Category[i]]]
      if (df$Qty[i] >= 2 || !(df$ItemName[i] %in% valid)) {
        true_tiers[i] <- "Replica"
      }
    }
  }
  
  unit_prices <- base_vals
  for(i in 1:nrow(df)) {
    c <- df$Category[i]
    t <- true_tiers[i]
    if (t == "Replica") { unit_prices[i] <- 0 }
    else if (t == "Unique") { unit_prices[i] <- Inf }
    else {
      if (c %in% c("Sword", "Lance", "Dagger", "Axe", "Mace", "Stave", "Bow")) {
        if(t=="Decent") unit_prices[i] = base_vals[i] + 50
        if(t=="Rare") unit_prices[i] = base_vals[i] + 100
        if(t=="Flawless") unit_prices[i] = base_vals[i] + 200
      } else if (c %in% c("Shield", "Armor")) {
        if(t=="Decent") unit_prices[i] = base_vals[i] * 2
        if(t=="Rare") unit_prices[i] = base_vals[i] * 4
        if(t=="Flawless") unit_prices[i] = base_vals[i] * 10
      } else {
        if(t=="Decent") unit_prices[i] = base_vals[i] ^ 2
        if(t=="Rare") unit_prices[i] = base_vals[i] ^ 4
        if(t=="Flawless") unit_prices[i] = base_vals[i] ^ 8
      }
    }
  }
  
  mults <- rep(1.0, nrow(df))
  for(i in 1:nrow(df)) {
    if(df$Job[i] == "Merchant") mults[i] <- mults[i] * 0.9
    if(df$Job[i] == "Saber" && df$Category[i] == "Sword") mults[i] <- mults[i] * 1.2
    if(df$Job[i] == "Archer" && df$Category[i] == "Bow") mults[i] <- mults[i] * 1.2
    if(df$Job[i] == "Lancer" && df$Category[i] == "Lance") mults[i] <- mults[i] * 1.2
    
    if(df$Economy[i] == "Poor") mults[i] <- mults[i] * 1.1
    if(df$Economy[i] == "Rich") mults[i] <- mults[i] * 0.5
  }
  
  return(ceiling(unit_prices * mults * df$Qty))
}

# ★ 助教端產生 30 筆測資，壓力測試
test_queue <- generate_queue(30)
standard_totals <- get_standard_answer(test_queue)

tryCatch({
  run_interactive_test <- function(...) { invisible(NULL) }
  
  source("homework.R", encoding = "UTF-8")
  
  student_result_df <- myfunction(test_queue)
  
  comparison_table <- data.frame(
    ID = test_queue$CustomerID,
    Job = test_queue$Job,
    Econ = test_queue$Economy,
    Cat = test_queue$Category,
    Tier = test_queue$ClaimedTier,
    Qty = test_queue$Qty,
    Standard = standard_totals,
    Student = student_result_df$TotalPrice,
    stringsAsFactors = FALSE
  )
  
  comparison_table$IsCorrect <- mapply(function(std, stu) {
    isTRUE(all.equal(as.numeric(std), as.numeric(stu)))
  }, comparison_table$Standard, comparison_table$Student)
  
  cat("====================================================\n")
  cat("                    批改結果報告 (30筆)             \n")
  cat("====================================================\n")
  print(comparison_table)
  
  correct_count <- sum(comparison_table$IsCorrect, na.rm = TRUE)
  cat(sprintf("\n>>> 最終成績：答對 %d / %d 題\n", correct_count, nrow(comparison_table)))
  
}, error = function(e) {
  cat("\n[錯誤] 學生程式碼執行失敗：\n", e$message, "\n")
})