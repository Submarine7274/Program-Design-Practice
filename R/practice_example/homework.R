# ==========================================
# homework.R (學生自己寫的 Dataframe 與條件判斷)
# ==========================================

source("env.R", encoding = "UTF-8")

myfunction <- function(df) {
  
  df$Job <- trimws(as.character(df$Job))
  df$Economy <- trimws(as.character(df$Economy))
  
  df$Job[is.na(df$Job)|df$Job == ""] <- "Unknown"
  df$Economy[is.na(df$Economy)|df$Economy == ""] <- "Unknown"
  
  base_prices <- c(Sword=10, Shield=50, Armor=100, Lance=5, Dagger=5, Axe=15, 
                   Mace=15, Stave=15, Bow=30, Elixir=10, Ring=5, Amulets=5, Belt=3, Grimoire=5)
  base_vals <- unname(base_prices[df$Category])
  
  is_valid_name <- mapply(function(cat, item) {
    
    if (is.na(cat) || is.na(item)) {
      return(FALSE)
    }
    
    valid_names <- unique_items_list[[cat]]
    
    if (is.null(valid_names)) {
      return(FALSE)
    }
    
    item %in% valid_names
    
  }, df$Category, df$ItemName)
  
  is_unique <- df$ClaimedTier == "Unique"
  
  is_replica <- is_unique & (
    df$Qty >= 2 | !is_valid_name
  )
  
  true_tiers <- df$ClaimedTier
  
  true_tiers[is_replica] <- "Replica"
  
  unit_prices <- base_vals
  calculate_price <- function(category, tier, base) {
    
    if (tier == "Replica") return(0)
    if (tier == "Unique") return(Inf)
    
    if (category %in% c(
      "Sword", "Lance", "Dagger",
      "Axe", "Mace", "Stave", "Bow"
    )) {
      
      bonus <- c(
        Common = 0,
        Decent = 50,
        Rare = 100,
        Flawless = 200
      )
      
      return(base + bonus[tier])
    }
    
    if (category %in% c("Shield", "Armor")) {
      
      multiplier <- c(
        Common = 1,
        Decent = 2,
        Rare = 4,
        Flawless = 10
      )
      
      return(base * multiplier[tier])
    }
    
    exponent <- c(
      Common = 1,
      Decent = 2,
      Rare = 4,
      Flawless = 8
    )
    
    return(base ^ exponent[tier])
  }
  unit_prices <- unname(mapply(
    calculate_price,
    df$Category,
    true_tiers,
    base_vals
  ))
  
  # idx_add <- df$Category %in% c("Sword", "Lance", "Dagger", "Axe", "Mace", "Stave", "Bow")
  # unit_prices <- ifelse(idx_add & true_tiers == "Decent", base_vals + 50, unit_prices)
  # unit_prices <- ifelse(idx_add & true_tiers == "Rare", base_vals + 100, unit_prices)
  # unit_prices <- ifelse(idx_add & true_tiers == "Flawless", base_vals + 200, unit_prices)
  # 
  # idx_mul <- df$Category %in% c("Shield", "Armor")
  # unit_prices <- ifelse(idx_mul & true_tiers == "Decent", base_vals * 2, unit_prices)
  # unit_prices <- ifelse(idx_mul & true_tiers == "Rare", base_vals * 4, unit_prices)
  # unit_prices <- ifelse(idx_mul & true_tiers == "Flawless", base_vals * 10, unit_prices)
  # 
  # idx_pow <- df$Category %in% c("Ring", "Amulets", "Belt", "Grimoire", "Elixir")
  # unit_prices <- ifelse(idx_pow & true_tiers == "Decent", base_vals ^ 2, unit_prices)
  # unit_prices <- ifelse(idx_pow & true_tiers == "Rare", base_vals ^ 4, unit_prices)
  # unit_prices <- ifelse(idx_pow & true_tiers == "Flawless", base_vals ^ 8, unit_prices)
  # 
  # unit_prices <- ifelse(true_tiers == "Replica", 0, unit_prices)
  # unit_prices <- ifelse(true_tiers == "Unique", Inf, unit_prices)
  
  multipliers <- rep(1.0, nrow(df))
  multipliers <- ifelse(df$Job == "Merchant", multipliers * 0.9, multipliers)
  
  weapon_match <- (df$Job == "Saber" & df$Category == "Sword") | 
    (df$Job == "Archer" & df$Category == "Bow") | 
    (df$Job == "Lancer" & df$Category == "Lance")
  multipliers <- ifelse(weapon_match, multipliers * 1.2, multipliers)
  
  multipliers <- ifelse(df$Economy == "Poor", multipliers * 1.1, multipliers)
  multipliers <- ifelse(df$Economy == "Rich", multipliers * 0.5, multipliers)
  
  df$TotalPrice <- ceiling(unit_prices * multipliers * df$Qty)
  return(df)
}

# ★ 學生在此呼叫教師環境提供的測試函式，傳入自己寫的邏輯
# 如果想關閉互動測試，把這行註解掉即可
run_interactive_test(myfunction)