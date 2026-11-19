# ==========================================
# env.R (提供給學生的環境檔)
# ==========================================



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

make_typo <- function(item_name, valid_names) {
  
  chars <- strsplit(item_name, "")[[1]]
  
  valid_pos <- which(grepl("[a-zA-Z]", chars))
  
  if (length(valid_pos) == 0) {
    stop("無法產生錯字")
  }
  
  candidates <- c(letters, LETTERS)
  
  typo_candidates <- unlist(lapply(valid_pos, function(pos) {
    
    new_chars <- lapply(
      setdiff(candidates, chars[pos]),
      function(new_char) {
        temp <- chars
        temp[pos] <- new_char
        paste0(temp, collapse = "")
      }
    )
    
    unlist(new_chars)
  }))
  
  typo_candidates <- setdiff(
    typo_candidates,
    valid_names
  )
  
  sample(typo_candidates, 1)
}
validate_queue <- function(df) {
  
  required_cols <- c(
    "CustomerID",
    "Category",
    "Job",
    "Economy",
    "ClaimedTier",
    "Qty",
    "ItemName"
  )
  
  missing_cols <- setdiff(required_cols, names(df))
  
  if (length(missing_cols) > 0) {
    stop(
      paste(
        "缺少欄位：",
        paste(missing_cols, collapse = ", ")
      )
    )
  }
  
  if (any(is.na(df$Category))) {
    stop("Category 不可為 NA")
  }
  
  if (any(!df$Category %in% names(unique_items_list))) {
    stop("發現不存在的裝備分類")
  }
  
  if (!is.numeric(df$Qty) ||
      anyNA(df$Qty) ||
      any(!is.finite(df$Qty)) ||
      any(df$Qty < 1 | df$Qty != floor(df$Qty))) {
    
    stop("Qty 必須為正整數")
  }
  if (!is.data.frame(df)) {
    stop("輸入資料必須是 Dataframe")
  }
  
  TRUE
}
# ★ 強制安插 10 種必測情境的佇列產生器
generate_queue <- function(n = 10) {
  if (n < 10) n <- 10 # 確保至少能測滿 10 個核心情境
  
  df <- data.frame(CustomerID = 1:n, stringsAsFactors = FALSE)
  
  # 預先填入隨機資料
  df$Category <- sample(names(unique_items_list), n, replace = TRUE)
  df$Job <- sample(c("Saber", "Archer", "Lancer", "Merchant", "Unknown"), n, replace = TRUE)
  df$Economy <- sample(c("Poor", "Unknown", "Rich"), n, replace = TRUE)
  df$ClaimedTier <- sample(c("Common", "Decent", "Rare", "Flawless", "Unique"), n, replace = TRUE)
  df$Qty <- sample(1:3, n, replace = TRUE, prob = c(0.7, 0.2, 0.1))
  df$ItemName <- character(n)
  
  # ==========================================
  # 覆寫前 10 筆為必測極端情境 (Edge Cases)
  # ==========================================
  # 情境 1：一般裝備 (測試基礎邏輯，無任何加成)
  df$ClaimedTier[1] <- sample(c("Common", "Decent", "Rare", "Flawless"), 1)
  df$Job[1] <- "Unknown"
  df$Economy[1] <- "Unknown"
  
  # 情境 2：真正的獨特 (測試 Inf 判斷)
  df$ClaimedTier[2] <- "Unique"
  df$Qty[2] <- 1
  
  # 情境 3：假貨陷阱 A - 獨特裝但數量大於等於 2
  df$ClaimedTier[3] <- "Unique"
  df$Qty[3] <- sample(2:3, 1)
  
  # 情境 4：假貨陷阱 B - 獨特裝但名字有錯字 
  df$ClaimedTier[4] <- "Unique"
  df$Qty[4] <- 1
  
  # 情境 5：隱藏資訊測試 - 職業與財力為 NA
  df$ClaimedTier[5] <- sample(c("Common", "Decent", "Rare", "Flawless"), 1)
  df$Job[5] <- NA
  df$Economy[5] <- NA
  
  # 情境 6：職業專武加成 (測試 1.2 倍與條件判定)
  combo <- list(c("Saber", "Sword"), c("Archer", "Bow"), c("Lancer", "Lance"))
  chosen <- combo[[sample(1:3, 1)]]
  df$Job[6] <- chosen[1]
  df$Category[6] <- chosen[2]
  df$ClaimedTier[6] <- sample(c("Common", "Decent", "Rare", "Flawless"), 1)
  
  # 情境 7：多重乘數疊加 (測試 Merchant 0.9 * Rich 0.5)
  df$Job[7] <- "Merchant"
  df$Economy[7] <- "Rich"
  df$ClaimedTier[7] <- sample(c("Common", "Decent", "Rare", "Flawless"), 1)
  
  # 情境 8：髒資料 (測試 trimws 是否有確實執行)
  df$Job[8] <- " Saber "
  df$Economy[8] <- " Poor "
  df$Category[8] <- "Sword"
  df$ClaimedTier[8] <- sample(c("Common", "Decent", "Rare", "Flawless"), 1)
  
  # 情境 9：指數計算極端值 (測試 Ring/Amulet 等 ^8)
  df$Category[9] <- sample(c("Ring", "Amulets", "Belt", "Grimoire", "Elixir"), 1)
  df$ClaimedTier[9] <- "Flawless"
  
  # 情境 10：倍數乘法計算 (測試 Shield/Armor *4)
  df$Category[10] <- sample(c("Shield", "Armor"), 1)
  df$ClaimedTier[10] <- "Rare"
  
  # 統一產生 ItemName
  for(i in 1:n) {
    if (df$ClaimedTier[i] == "Unique") {
      name <- sample(unique_items_list[[df$Category[i]]], 1)
      
      if (i == 4) {
        name <- make_typo(name, unique_items_list[[df$Category[i]]])
      } else if (i == 2 || i == 3) {
        name <- name
      } else {
        if (sample(c(TRUE, FALSE), 1, prob = c(0.3, 0.7))) {
          name <- make_typo(name, unique_items_list[[df$Category[i]]])
        }
      }
      df$ItemName[i] <- name
    } else {
      df$ItemName[i] <- paste("Unknown", df$Category[i])
    }
  }
  validate_queue(df)
  return(df)
}

# 互動測試系統 (預設給 10 題情境)
run_interactive_test <- function(student_func) {
  if (exists("GRADING_MODE") && GRADING_MODE) return(invisible(NULL))
  set.seed(20261116)
  #種子在此設定
  test_queue <- generate_queue(10)
  
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
  
  cat("【系統】自主測試開始！共 10 位客人，請心算價格來驗證你的程式碼。\n\n")
  
  for(i in 1:nrow(test_queue)) {
    c_item <- test_queue$ItemName[i]
    c_qty <- test_queue$Qty[i]
    c_cat <- test_queue$Category[i]
    c_tier <- test_queue$ClaimedTier[i]
    
    c_job <- ifelse(is.na(test_queue$Job[i]), "Unknown", paste0("'", test_queue$Job[i], "'"))
    c_econ <- ifelse(is.na(test_queue$Economy[i]), "Unknown", paste0("'", test_queue$Economy[i], "'"))
    
    cat("--------------------------------------------------\n")
    cat(sprintf("[客人 %02d] 物品：%s x %d (分類：%s, 聲稱：%s)\n", i, c_item, c_qty, c_cat, c_tier))
    cat(sprintf("          職業：%s |財力：%s\n", c_job, c_econ))
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
      else if (player_quote == Inf) cat("【評價】Overvalued Replica (敝帚自珍)\n")
      else cat("【評價】Eye Doctor (該去看眼科了)\n")
    } else if (is.infinite(system_price)) {
      if (player_quote == Inf) cat("【評價】Perfect (完美的估價)\n")
      else if (player_quote == 0) cat("【評價】Missed Treasure (錯失珍寶)\n")
      else cat("【評價】Eye Doctor (該去看眼科了)\n")
    } else {
      if (player_quote == Inf) {
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