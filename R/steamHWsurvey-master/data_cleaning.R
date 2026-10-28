# 模組：載入必要套件
library(tidyverse)
library(readr)
library(ggrepel)
# 模組：全域 UI 設定檔 (繪圖前必須先載入)
current_os <- Sys.info()["sysname"]
dynamic_font <- ifelse(current_os == "Darwin", "PingFang TC", "Microsoft JhengHei UI")
ui_config <- list(
  font_family = dynamic_font,
  base_size = 15, title_size = 22, subtitle_size = 14, axis_title_size = 16,
  axis_text_size = 13, legend_title_size = 14, legend_text_size = 13,
  label_size = 3.5, watermark_size = 4, nudge_ratio = 0.15,
  segment_color = "#555555", segment_linewidth = 0.8, segment_linetype = "dashed",
  color_normal = "#555555", color_alert = "#d73027", color_text = "#333333"
)

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
#cat("=== Steam 歷史抽樣災難排行榜 ===\n")
#print(disaster_months, n = Inf, width = Inf)
View(disaster_months)
View(anomaly_detector)
# 模組：繪製抽樣災難時間軸氣泡圖
p_timeline <- ggplot(disaster_months, aes(x = 異常峰值月, y = 0)) +
  # 畫出中間的時間軸底線
  geom_hline(yintercept = 0, color = ui_config$color_normal, linewidth = 1) +
  
  # 繪製氣泡：大小代表牽涉數量，顏色深淺代表嚴重度
  geom_point(
    aes(size = 牽涉硬體數量, fill = 牽涉硬體數量), 
    shape = 21, color = "white", stroke = 1.5, alpha = 0.85
  ) +
  
  # 在氣泡上方加上日期標籤與數量，使用 ggrepel 避免重疊
  geom_text_repel(
    aes(label = paste0(format(異常峰值月, "%Y-%m"), "\n(", 牽涉硬體數量, "項)")),
    direction = "y", nudge_y = 0.5, segment.size = 0.4, 
    segment.color = ui_config$segment_color, color = ui_config$color_text, 
    family = ui_config$font_family, size = ui_config$label_size, fontface = "bold"
  ) +
  
  # 設定氣泡大小的縮放比例範圍 (可依照視覺感受微調)
  scale_size_continuous(range = c(5, 25), guide = "none") +
  # 設定氣泡顏色的漸層，越嚴重越紅
  scale_fill_gradient(low = "#fcae91", high = ui_config$color_alert, guide = "none") +
  
  # 調整 X 軸時間刻度
  scale_x_date(date_breaks = "2 years", date_labels = "%Y") +
  # 隱藏 Y 軸 (因為只是用來排版的虛擬軸)
  scale_y_continuous(limits = c(-1, 3)) +
  
  theme_minimal(base_size = ui_config$base_size, base_family = ui_config$font_family) +
  theme(
    axis.title.y = element_blank(),
    axis.text.y = element_blank(),
    axis.ticks.y = element_blank(),
    panel.grid.minor = element_blank(),
    panel.grid.major.y = element_blank(),
    plot.title = element_text(face = "bold", size = ui_config$title_size),
    plot.subtitle = element_text(size = ui_config$subtitle_size, color = ui_config$color_normal),
    axis.title.x = element_text(face = "bold", size = ui_config$axis_title_size),
    axis.text.x = element_text(size = ui_config$axis_text_size, color = ui_config$color_text)
  ) +
  labs(
    title = "Steam 歷史抽樣災難時間軸",
    subtitle = "氣泡大小代表單月異常突波牽涉的硬體項目數量 (規模越大代表系統性錯誤越嚴重)",
    x = "異常發生年份"
  )



# 印出圖表
print(p_timeline)
dir.create("steam_charts_output", showWarnings = FALSE)
ggsave(
  filename = file.path("steam_charts_output", "anomaly_timeline.png"),
  plot = p_timeline,
  width = 16,     
  height = 9,     
  dpi = 120       
)
cat("氣泡圖已成功儲存至 steam_charts_output/anomaly_timeline.png\n")
