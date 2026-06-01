# 載入必要套件
library(tidyverse)

# ==========================================
# 1. 讀取原始資料 (不進行任何平滑化，保留真實雜訊)
# ==========================================
df_raw <- read_csv("C:/Users/Efly01/Downloads/steamHWsurvey-master/shs.csv", show_col_types = FALSE) %>%
  drop_na(name, percentage) %>%
  mutate(date = as.Date(date, format = "%Y/%m/%d")) %>%
  filter(name != "Other", name != "Unspecified") %>%
  filter(percentage > 0)

# ==========================================
# 2. 建立「三點驗證 (倒 V 型)」突波偵測演算法
# ==========================================
anomaly_detector <- df_raw %>%
  # 依照硬體名稱分組，確保時間序列由舊到新排序
  group_by(category, name) %>%
  arrange(date, .by_group = TRUE) %>%
  mutate(
    # 抓取上個月 (t-1) 的資料
    prev_month_date = lag(date),
    prev_month_pct = lag(percentage),
    
    # 抓取下個月 (t+1) 的資料
    next_month_date = lead(date),
    next_month_pct = lead(percentage),
    
    # 計算前後落差 (一階導數差值)
    # surge_amount: 當月比上個月暴增了多少
    # drop_amount: 下個月比當月崩跌了多少
    surge_amount = percentage - prev_month_pct,
    drop_amount = next_month_pct - percentage
  ) %>%
  
  # 【核心邏輯】：地毯式掃描所有歷史資料
  # 條件：當月比上個月暴增 >= 2%，且下個月瞬間崩跌 <= -2%
  filter(surge_amount >= 0.02 & drop_amount <= -0.02) %>%
  ungroup() %>%
  
  # 整理欄位並賦予直觀的中文名稱
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

# ==========================================
# 3. 統計「橫斷面群聚效應」(找出系統性抽樣災難)
# ==========================================
disaster_months <- anomaly_detector %>%
  group_by(異常峰值月) %>%
  summarise(
    牽涉硬體數量 = n(),
    # 收集該月發生異常的分類，用逗號分隔，檢驗是否跨領域崩潰
    波及分類 = paste(unique(分類), collapse = ", ")
  ) %>%
  # 依照牽涉硬體數量由多到少進行排序，最嚴重的災難會排在最上面
  arrange(desc(牽涉硬體數量))

# ==========================================
# 4. 輸出檢驗報告
# ==========================================
cat("=== Steam 歷史抽樣災難排行榜 ===\n")
# 強制印出所有欄位與列數，避免 tibble 預設的截斷機制
print(disaster_months, n = Inf, width = Inf)
View(disaster_months)
View(anomaly_detector)