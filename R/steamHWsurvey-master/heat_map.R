# 載入必要套件
library(tidyverse)
library(zoo)

# 1. 讀取基礎資料
df_shs <- read_csv("C:/Users/Efly01/Downloads/steamHWsurvey-master/shs.csv", show_col_types = FALSE) %>%
  drop_na(name, percentage) %>%
  mutate(date = as.Date(date, format = "%Y/%m/%d")) %>%
  filter(name != "Other", name != "Unspecified") %>%
  filter(percentage > 0)

# ==========================================
# 2. 指定觀察名單與建立相關性資料集
# ==========================================
# 步驟 2-1：定義精確的硬體白名單 (Whitelist)
# 確保字串與 Steam 原始資料的命名完全一致
target_hardware <- c(
  "[System RAM] 4 GB",
  "[System RAM] 8 GB",
  "[System RAM] 16 GB",
  "[System RAM] 32 GB",
  "[Video Card Description] NVIDIA GeForce RTX 4060",
  "[Video Card Description] NVIDIA GeForce RTX 3060",
  "[Video Card Description] NVIDIA GeForce RTX 2060",
  "[Video Card Description] NVIDIA GeForce GTX 1060",
  "[Physical CPUs] 4 cpus",
  "[Physical CPUs] 6 cpus",
  "[Physical CPUs] 8 cpus",
  "[Physical CPUs] 12 cpus"
)

# 步驟 2-2：資料去重與白名單過濾
clean_base_df <- df_shs %>%
  # 將時間窗格設定在 2019 年以後，以涵蓋 1060 與 2060 的全盛交替期
  filter(date >= as.Date("2019-01-01")) %>%
  mutate(unique_name = paste0("[", category, "] ", name)) %>%
  
  # 【關鍵修改】：放棄動態排名，直接以白名單進行嚴格過濾
  filter(unique_name %in% target_hardware) %>%
  
  # 強制去重防護
  group_by(unique_name, date) %>%
  summarise(percentage = mean(percentage, na.rm = TRUE), .groups = "drop")

# 步驟 2-3：計算指定硬體的月變化率
cor_data <- clean_base_df %>%
  group_by(unique_name) %>%
  arrange(date, .by_group = TRUE) %>%
  mutate(
    # 套用已知的系統性抽樣災難黑名單
    clean_pct = case_when(
      date >= as.Date("2017-08-01") & date <= as.Date("2018-05-01") ~ NA_real_,
      date %in% as.Date(c(
        "2020-12-01", "2022-10-01", "2023-03-01", "2023-10-01", 
        "2024-05-01", "2024-10-01", "2025-02-01", "2026-02-01"
      )) ~ NA_real_,
      TRUE ~ percentage
    ),
    
    # 執行安全線性內插
    smoothed_pct = if(sum(!is.na(clean_pct)) >= 2) {
      na.approx(clean_pct, na.rm = FALSE)
    } else {
      clean_pct
    },
    
    # 取一階導數做為相關性特徵
    true_change = smoothed_pct - lag(smoothed_pct)
  ) %>%
  ungroup()

# ==========================================
# 3. 矩陣變換與皮爾森相關係數計算
# ==========================================
wide_data <- cor_data %>%
  # 這裡改用 unique_name
  select(date, unique_name, true_change) %>%
  # 由於前面已經強制去重，這裡絕對不會再產生 list-cols 警告
  pivot_wider(names_from = unique_name, values_from = true_change) %>%
  select(-date)

# 矩陣現在是純淨的浮點數，cor() 可以安全執行
cor_matrix <- cor(wide_data, use = "pairwise.complete.obs")

cor_df <- as.data.frame(as.table(cor_matrix)) %>%
  rename(Hardware_A = Var1, Hardware_B = Var2, Correlation = Freq)
# ==========================================
# 4. 繪製相關性熱力圖 (Correlation Heatmap)
# ==========================================
p_cor <- ggplot(cor_df, aes(x = Hardware_A, y = Hardware_B, fill = Correlation)) +
  # geom_tile 在畫布上映射矩陣方塊
  geom_tile(color = "white") +
  
  # 設定雙色漸層映射：
  # 紅色代表正相關 (+1，同進同退)
  # 藍色代表負相關 (-1，相互排擠/世代交替)
  # 白色代表無相關 (0)
  scale_fill_gradient2(
    low = "#2166ac", mid = "#f7f7f7", high = "#b2182b", midpoint = 0,
    limit = c(-1, 1), name = "相關係數\n(Pearson r)"
  ) +
  
  theme_minimal() +
  theme(
    # 調整文字角度避免重疊
    axis.text.x = element_text(angle = 45, hjust = 1, face = "bold", size = 9, color = "#333333"),
    axis.text.y = element_text(face = "bold", size = 9, color = "#333333"),
    panel.grid = element_blank(),
    plot.margin = margin(t = 20, r = 20, b = 20, l = 20)
  ) +
  labs(
    title = "Steam 主流硬體月變化率相關性 (Pearson Correlation)",
    subtitle = "紅色代表正相關 (同進同退)，藍色代表負相關 (相互排擠/世代交替)",
    x = NULL, y = NULL
  )

# 顯示圖表
print(p_cor)