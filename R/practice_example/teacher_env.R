# ==========================================
# teacher_env.R (提供給學生的環境檔)
# ==========================================

# 鎖定亂數種子
set.seed(20261116)

unique_items_list <- list(
  Sword = c("Excalibur", "Aroundight", "Kusanagi-no-Tsurugi", "Goujian", "Joyeuse", "Honjo Masamune", "Zulfiqar", "The Saviour", "Paradoxica", "Cospri's Malice", "The Golden Charlatan", "Starforge", "Voidforge"),
  Shield = c("Aegis", "Shield of Achilles", "Pridwen", "Ancile", "Battersea Shield", "Sutton Hoo Shield", "Ishtar Gate", "Golden Gate", "Gate of China", "The Squire", "Mahuxotl's Machination", "Svalinn"),
  Armor = c("Kavacha", "Armour of the Kelly gang", "Atziri's Acuity", "Dialla's Malefaction", "Shavronne's Wrappings", "Járngreipr", "Víðarr's Leather Shoe", "Talaria", "Tarnkappe"),
  Lance = c("Spear of Longinus", "Tonbokiri", "Gungnir", "Spear of Fuchai", "Trident", "Gáe Bulg", "Rhongomyniad"),
  Dagger = c("Carnwennan", "keris of mpu gandring", "Tutankhamun's Meteoric Iron Dagger", "Dagger of Time", "Bino's Kitchen Knife"),
  Axe = c("Gorehowl", "Parashu", "Axe of Perun", "The Axe of Stamford Bridge", "Soul Taker"),
  Mace = c("Ghal Maraz", "Doomhammer", "Mjölnir", "Uchide no kozuchi", "Nebulis", "Foulborn Void Battery"),
  Stave = c("Ruyi Jingu Bang", "Staff of Moses", "Rod of Asclepius", "Caduceus", "The Annihilating Light", "Pledge of Hands"),
  Bow = c("Tong Gong", "Bow of Odysseus", "Gandiva", "Windripper", "Reach of the Council"),
  Elixir = c("Water of Lethe", "Elixir of Life", "Bottled Faith", "Dying Sun", "Oriath's End", "Progenesis", "Sin's Rebirth", "Taste of Hate", "Vessel of Vinktar", "Wine of the Prophet"),
  Ring = c("Draupnir", "Seal of Solomon", "Ring of Gyges", "The One Ring", "Ring of the Fisherman", "Nimis", "Lost Unity"),
  Amulets = c("The Hope Diamond", "Brísingamen", "Necklace of Harmonia", "Heart of the Ocean", "Defiance of Destiny"),
  Belt = c("Megingjörð", "Kestos Himas", "Girdle of Hippolyta", "Girdle of Thomas", "Championship Belt", "Mageblood", "Headhunter"),
  Grimoire = c("Codex Gigas", "Voynich Manuscript", "Lemegeton", "Book of Thoth", "Book of Vishanti", "R'lyeh Text")
)

make_typo <- function(item_name) {
  pos <- sample(1:nchar(item_name), 1)
  orig_char <- substr(item_name, pos, pos)
  candidates <- setdiff(c(letters, LETTERS), orig_char)
  substr(item_name, pos, pos) <- sample(candidates, 1)
  return(item_name)
}

# ★ 改寫後的佇列產生器：強制安插所有邊界條件 (Edge Cases)
generate_queue <- function() {
  n <- 5
  df <- data.frame(CustomerID = 1:n, stringsAsFactors = FALSE)
  
  # 分類與基本屬性依舊隨機
  df$Category <- sample(names(unique_items_list), n, replace = TRUE)
  df$Job <- sample(c("Saber", "Archer", "Lancer", "Merchant", "Normal"), n, replace = TRUE)
  df$Economy <- sample(c("Poor", "Normal", "Rich"), n, replace = TRUE)
  
  df$ClaimedTier <- character(n)
  df$Qty <- numeric(n)
  df$ItemName <- character(n)
  
  # 客人 1：一般裝備 (測試基礎邏輯)
  df$ClaimedTier[1] <- sample(c("Common", "Decent", "Rare", "Flawless"), 1)
  df$Qty[1] <- sample(1:3, 1)
  df$ItemName[1] <- paste("Unknown", df$Category[1])
  
  # 客人 2：真正的獨特神兵 (測試 Inf 判斷)
  df$ClaimedTier[2] <- "Unique"
  df$Qty[2] <- 1
  df$ItemName[2] <- sample(unique_items_list[[df$Category[2]]], 1)
  
  # 客人 3：假貨陷阱 A - 獨特裝但數量大於等於 2
  df$ClaimedTier[3] <- "Unique"
  df$Qty[3] <- sample(2:3, 1) # 強制給 2 或 3
  df$ItemName[3] <- sample(unique_items_list[[df$Category[3]]], 1)
  
  # 客人 4：假貨陷阱 B - 獨特裝但名字有錯字
  df$ClaimedTier[4] <- "Unique"
  df$Qty[4] <- 1
  df$ItemName[4] <- make_typo(sample(unique_items_list[[df$Category[4]]], 1))
  
  # 客人 5：隱藏資訊測試 - 職業與財力為 NA (測試防呆)
  df$ClaimedTier[5] <- sample(c("Common", "Decent", "Rare", "Flawless"), 1)
  df$Qty[5] <- 1
  df$ItemName[5] <- paste("Unknown", df$Category[5])
  df$Job[5] <- NA
  df$Economy[5] <- NA
  
  return(df)
}

# 提供給學生的互動測試系統
run_interactive_test <- function(student_func) {
  # 測試時不鎖死 Seed，讓裝備名稱隨機變換，但情境 100% 固定
  test_queue <- generate_queue()
  
  computed_df <- tryCatch({
    student_func(test_queue)
  }, error = function(e) {
    cat("【系統錯誤】你的函式發生報錯：\n", e$message, "\n")
    return(NULL)
  })
  
  if (is.null(computed_df)) return()
  if (!"TotalPrice" %in% names(computed_df)) {
    cat("【系統警告】你的回傳結果缺少 TotalPrice 欄位！\n")
    return()
  }
  
  cat("【系統】自主測試開始！請心算價格來驗證你的程式碼是否正確。\n\n")
  
  for(i in 1:nrow(test_queue)) {
    c_item <- test_queue$ItemName[i]
    c_qty <- test_queue$Qty[i]
    c_cat <- test_queue$Category[i]
    c_tier <- test_queue$ClaimedTier[i]
    
    c_job <- ifelse(is.na(test_queue$Job[i]), "(隱藏)", trimws(test_queue$Job[i]))
    c_econ <- ifelse(is.na(test_queue$Economy[i]), "(隱藏)", trimws(test_queue$Economy[i]))
    
    cat("--------------------------------------------------\n")
    cat(sprintf("[客人 %d] 物品：%s x %d (分類：%s, 聲稱：%s)\n", i, c_item, c_qty, c_cat, c_tier))
    cat(sprintf("          觀察 - 職業：%s | 財力：%s\n", c_job, c_econ))
    cat("--------------------------------------------------\n")
    
    player_input <- readline(prompt = "心算報價 (數字/Inf，或 exit 退出)：")
    if (tolower(trimws(player_input)) == "exit") break
    
    player_quote <- as.numeric(player_input)
    system_price <- computed_df$TotalPrice[i] 
    
    if (is.na(player_quote)) {
      cat("【結果】無效輸入。\n\n")
      next
    }
    
    if (is.na(system_price)) {
      cat("【系統警告】你的程式在此筆資料算出了 NA！\n")
    } else if (system_price == 0) {
      if (player_quote == 0) cat("【評價】Perfect (完美的估價)\n")
      else if (is.infinite(player_quote)) cat("【評價】Overvalued Replica (敝帚自珍)\n")
      else cat("【評價】Eye Doctor (該去看眼科了)\n")
    } else if (is.infinite(system_price)) {
      if (is.infinite(player_quote)) cat("【評價】Perfect (完美的估價)\n")
      else if (player_quote == 0) cat("【評價】Missed Treasure (錯失珍寶)\n")
      else cat("【評價】Eye Doctor (該去看眼科了)\n")
    } else {
      if (is.infinite(player_quote)) {
        cat("【評價】Eye Doctor (該去看眼科了)\n")
      } else {
        diff_ratio <- abs(player_quote - system_price) / system_price
        if (diff_ratio == 0) cat("【評價】Perfect (完美的估價)\n")
        else if (diff_ratio <= 0.30) cat("【評價】Reasonable (合理的估價)\n")
        else if (diff_ratio <= 0.50) cat("【評價】Terrible (糟糕的估價)\n")
        else cat("【評價】Eye Doctor (該去看眼科了)\n")
      }
    }
    
    cat(sprintf(" (你的程式計算結果為：%s)\n\n", ifelse(is.infinite(system_price), "Inf", system_price)))
  }
}