# 模組：載入必要套件
library(tidyverse)

# 模組：讀取原始資料 (保留真實雜訊)
if (requireNamespace("rstudioapi", quietly = TRUE) && rstudioapi::isAvailable()) {
  setwd(dirname(rstudioapi::getActiveDocumentContext()$path))
} else {
  warning("未偵測到 RStudio 環境。請確保工作目錄 (getwd()) 已設定為腳本所在資料夾。")
}

target_file <- "shs.csv"
if (!file.exists(target_file)) {
  stop(sprintf("錯誤：在當前目錄 (%s) 下找不到 '%s'。請確認工作目錄設定是否正確。", getwd(), target_file))
}
df_raw <- read_csv(target_file, show_col_types = FALSE) %>%
  drop_na(name, percentage) %>%
  mutate(date = as.Date(date, format = "%Y/%m/%d")) %>%
  filter(name != "Other", name != "Unspecified") %>%
  filter(percentage > 0)

# 模組：建立突波偵測演算法
anomaly_detector <- df_raw %>%
  group_by(category, name) %>%
  arrange(date, .by_group = TRUE) %>%
  mutate(
    prev_month_date = lag(date),
    prev_month_pct = lag(percentage),
    next_month_date = lead(date),
    next_month_pct = lead(percentage),
    surge_amount = percentage - prev_month_pct,
    drop_amount = next_month_pct - percentage
  ) %>%
  filter(surge_amount >= 0.02 & drop_amount <= -0.02) %>%
  ungroup() %>%
  select(
    分類 = category, 
    硬體名稱 = name, 
    上個月 = prev_month_date, 
    上月市佔 = prev_month_pct, 
    異常峰值月 = date,
    峰值市佔 = percentage,
    下個月 = next_month_date, 
    下月市佔 = next_month_pct, 
    暴增幅度 = surge_amount,
    崩跌幅度 = drop_amount
  )

# 模組：統計異常橫斷面群聚效應
disaster_months <- anomaly_detector %>%
  group_by(異常峰值月) %>%
  summarise(
    牽涉硬體數量 = n(),
    波及分類 = paste(unique(分類), collapse = ", ")
  ) %>%
  arrange(desc(牽涉硬體數量))

# 模組：輸出檢驗報告
cat("=== Steam 歷史抽樣災難排行榜 ===\n")
print(disaster_months, n = Inf, width = Inf)
View(disaster_months)
View(anomaly_detector)