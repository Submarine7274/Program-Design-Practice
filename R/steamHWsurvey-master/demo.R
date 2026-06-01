# 載入資料處理與視覺化必要套件
library(tidyverse)
library(scales)
library(zoo)
library(ggrepel)

# ==========================================
# 4. 模組化圖表匯出函式 (1920x1080 FHD 輸出版)
# ==========================================
export_steam_charts <- function(plot_list, output_dir = "steam_charts_output") {
  
  # 建立目標資料夾 (若已存在則忽略警告)
  dir.create(output_dir, showWarnings = FALSE)
  
  cat(sprintf("\n開始批次匯出圖表至資料夾: '%s' (解析度: 1920x1080)\n", output_dir))
  
  # 使用 purrr::walk 進行迭代匯出
  walk(names(plot_list), ~ {
    cat(sprintf(" - 正在匯出: %s ...\n", .x))
    plots <- plot_list[[.x]]
    
    if (!is.null(plots)) {
      # 將類別名稱的空格替換為底線，確保檔名在各作業系統皆合法
      safe_name <- str_replace_all(.x, " ", "_")
      
      # 匯出趨勢折線圖
      # 寬 16 英吋 * 120 DPI = 1920 Pixels
      # 高 9 英吋 * 120 DPI = 1080 Pixels
      if (!is.null(plots$trend)) {
        ggsave(
          filename = file.path(output_dir, sprintf("%s_trend.png", safe_name)), 
          plot = plots$trend, 
          width = 16,    
          height = 9,    
          dpi = 120      
        )
      }
      
      # 匯出單月爆發力長條圖
      if (!is.null(plots$change)) {
        ggsave(
          filename = file.path(output_dir, sprintf("%s_change.png", safe_name)), 
          plot = plots$change, 
          width = 16,    
          height = 9,    
          dpi = 120      
        )
      }
    } else {
      warning(sprintf("跳過 %s：圖表物件為空 (NULL)。", .x))
    }
  })
  
  cat(sprintf("\n匯出完成！所有 1920x1080 圖表已存入 '%s' 資料夾。\n", output_dir))
}

# ==========================================
# 0. 全域 UI 設定檔 (Global UI Configuration)
# 概念等同於 C++ 中的:
# struct UIConfig {
#     std::string font_family = "Microsoft JhengHei";
#     int base_size = 15;
#     ...
# };
# ==========================================
windowsFonts(JhengHei = windowsFont("Microsoft JhengHei UI"))
ui_config <- list(
  # 字型設定 (Windows 環境使用 "Microsoft JhengHei"，Mac 環境可改為 "PingFang TC")
  font_family = "JhengHei",
  
  # Theme 空間設定 (單位: pt，負責座標軸、標題等螢幕空間元素)
  base_size = 15,
  title_size = 22,
  subtitle_size = 14,
  axis_title_size = 16,
  axis_text_size = 13,
  legend_title_size = 14,
  legend_text_size = 13,
  
  # Geom 空間設定 (單位: mm，負責圖表內部的浮水印、標籤、資料點文字)
  label_size = 3.5,
  watermark_size = 4,
  nudge_ratio = 0.15,
  
  segment_color = "#555555",    # 加深顏色 (從淺灰 #aaaaaa 改為深灰 #555555)
  segment_linewidth = 0.8,      # 加粗線條 (預設約為 0.5)
  segment_linetype = "dashed",  # 改為虛線使其視覺上更連續明顯 (原本是 dotted)
  
  # 全域通用顏色 (將常用的提示色與警告色抽離)
  color_normal = "#555555",
  color_alert = "#d73027",
  color_text = "#333333"
)

# ==========================================
# 1. 建立全域事件字典 (Data-Driven Dictionary)
# ==========================================
event_dict <- list(
  "OS Version" = data.frame(
    date = as.Date(c("2009-10-22", "2012-10-26", "2013-10-17", "2015-07-29", "2020-01-14", "2021-10-05", "2023-01-10", "2025-10-14")),
    label = c("Win 7 正式發售", "Win 8 正式發售", "Win 8.1 正式發售", "Win 10 正式發售", "Win 7 終止支援", "Win 11 正式發售", "Win 8.1 終止支援", "Win 10 終止支援"),
    line_type = c("normal", "normal", "normal", "normal", "alert", "normal", "alert", "alert")
  ),
  "System RAM" = data.frame(
    date = as.Date(c("2013-11-15", "2017-03-23", "2020-11-12", "2022-11-30", "2024-01-19")),
    label = c("PS4/XOne 發售\n(8GB成新遊戲標配)", "PUBG 發售\n(推升 16GB)", "PS5/XSX 發售\n(16GB 成新遊戲標配)", "ChatGPT 問世\n(引爆本地 AI 需求)", "幻獸帕魯發售\n(首次有官方系統推薦為 32GB)"),
    line_type = rep("normal", 5)
  ),
  "Intel CPU Speeds" = data.frame(
    date = as.Date(c("2011-01-09", "2017-10-05", "2021-11-04", "2024-10-24")),
    label = c("Sandy Bridge 發布\n(第2代3.3 GHz 到 3.69 GHz為主力)", "Coffee Lake 發布\n(第8代擴增核心，多核心，時脈降低到2.8 GHz)", "Alder Lake 發布\n(第12代採用大小核，2.3 GHz ~ 2.6 GHz)", "Arrow Lake 發布\n(Core Ultra 2 桌機，時脈復古提升)"),
    line_type = rep("normal", 4)
  ),
  "Physical CPUs" = data.frame(
    date = as.Date(c("2017-03-02", "2017-10-05", "2021-11-04")),
    label = c("Ryzen 第一代發布\n(引爆多核大戰)", "Intel 第8代發布\n(普及 6 核心)", "Intel 第12代發布\n(大小核混合架構，核心數不再等於速度)"),
    line_type = rep("normal", 3)
  ),
  "Video Card Description" = data.frame(
    date = as.Date(c("2016-07-19", "2018-09-20", "2020-09-17", "2022-09-15", "2024-08-20")),
    label = c("GTX 1060 發售\n(一代神卡)", "RTX 20系發售\n(光追元年)", "RTX 30系發售\n(遇上礦潮)", "礦潮崩盤\n(3060起飛)", "黑神話發售\n(推升 40系)"),
    line_type = c("normal", "normal", "normal", "alert", "normal")
  ),
  "VRAM" = data.frame(
    date = as.Date(c("2016-07-19", "2020-09-17", "2022-08-22", "2023-01-24", "2023-02-24", "2024-01-24")),
    label = c("GTX 1060 發售\n(6GB 標準)", "RTX 30系發售\n(推升 8GB)", "Stable Diffusion 開源\n(引爆 12GB AI 繪圖)", "霍格華茲發售\n(8GB 遊戲危機)", "LLaMA 模型外流\n(推升 24GB LLM 需求)", "RTX 40 SUPER 發售\n(普及 12GB/16GB)"),
    line_type = c("normal", "normal", "normal", "alert", "normal", "normal")
  ),
  "Primary Display Resolution" = data.frame(
    date = as.Date(c("2012-08-21", "2018-09-20", "2020-11-12")),
    label = c("CS:GO 發售\n(鞏固 1080p 競技標準)", "RTX 20系發售\n(推動 1440p 普及)", "PS5/XSX 發售\n(家機開始支援4K 帶動 4K 換機潮)"),
    line_type = rep("normal", 3)
  ),
  "Multi-Monitor Desktop Resolution" = data.frame(
    date = as.Date(c("2014-02-18", "2018-01-01", "2020-03-11", "2023-01-01")),
    label = c("實況文化興起\n(推升多螢幕需求)", "144Hz 換機潮\n(雙 1080p 爆發)", "COVID-19 居家辦公\n(多螢幕大爆發)", "1440p 普及化\n(不對稱雙螢幕崛起)"),
    line_type = c("normal", "normal", "alert", "normal")
  ),
  "Language" = data.frame(
    date = as.Date(c("2017-03-23", "2017-10-01", "2018-02-16", "2021-02-09", "2021-08-01", "2022-10-01", "2023-10-01", "2024-10-01", "2025-02-01")),
    label = c("PUBG 發售\n(引爆簡中網咖狂熱)", "中國國慶日\n(十一長假突波)", "中國農曆新年\n(春節連假突波)", "蒸汽平台上線\n(政策隔離與盤整)", "永劫無間上市\n防沉迷法規發布", "中國國慶日\n(十一長假突波)", "中國國慶日\n(十一長假突波)", "中國國慶日\n(十一長假突波)", "中國農曆新年\n(春節連假突波)"),
    line_type = c("normal", "none", "none", "normal", "normal", "none", "none", "none", "none")
  ),
  "Total Hard Drive Space" = data.frame(
    date = as.Date(c("2013-11-15", "2019-10-25", "2020-11-12")),
    label = c("PS4/XOne 發售\n(淘汰 500GB)", "CoD: MW 發售\n(單款破 200GB 危機)", "PS5/XSX 發售\n(推升 2TB 需求)"),
    line_type = c("normal", "alert", "normal")
  )
  
)

# ==========================================
# 2. 讀取並標準化基礎資料
# ==========================================
df_shs <- read_csv("C:/Users/Efly01/Downloads/steamHWsurvey-master/shs.csv", show_col_types = FALSE) %>%
  drop_na(name, percentage) %>%
  mutate(date = as.Date(date, format = "%Y/%m/%d")) %>%
  filter(name != "Other", name != "Unspecified", percentage > 0)

df_shs <- df_shs %>%
  mutate(
    name = if_else(
      category == "Video Card Description",
      str_remove(name, "(?i)\\s+(Ti\\s+Super|Ti|Super|XTX|XT|GRE)$"),
      name
    ),
    name = if_else(
      category == "VRAM",
      case_when(
        str_detect(name, "1023 MB|1024 MB") ~ "1 GB",
        str_detect(name, "2047 MB|2048 MB") ~ "2 GB",
        str_detect(name, "3071 MB|3072 MB") ~ "3 GB",
        str_detect(name, "4095 MB|4096 MB") ~ "4 GB",
        str_detect(name, "6143 MB|6144 MB") ~ "6 GB",
        str_detect(name, "8191 MB|8192 MB") ~ "8 GB",
        str_detect(name, "10239 MB|10240 MB") ~ "10 GB",
        str_detect(name, "12287 MB|12288 MB") ~ "12 GB",
        str_detect(name, "16383 MB|16384 MB") ~ "16 GB",
        str_detect(name, "24575 MB|24576 MB") ~ "24 GB",
        TRUE ~ name
      ),
      name
    )
  ) %>%
  group_by(category, name, date) %>%
  summarise(percentage = sum(percentage, na.rm = TRUE), .groups = "drop")

# ==========================================
# 3. 定義模組化繪圖函式 (統一渲染管線)
# ==========================================
generate_category_plots <- function(dataset, target_category, top_n = 10) {
  
  cat_data <- dataset %>% filter(category == target_category)
  if (nrow(cat_data) == 0) return(NULL)
  
  top_items <- cat_data %>%
    group_by(name) %>%
    summarise(peak_percentage = max(percentage)) %>%
    slice_max(order_by = peak_percentage, n = top_n) %>%
    pull(name)
  
  plot_data <- cat_data %>% 
    filter(name %in% top_items) %>%
    group_by(name) %>%
    arrange(date, .by_group = TRUE) %>%
    mutate(
      clean_percentage = if (target_category == "Language") {
        case_when(
          date %in% as.Date(c("2020-12-01", "2023-03-01", "2024-05-01", "2026-02-01")) ~ NA_real_,
          TRUE ~ percentage
        )
      } else {
        case_when(
          date >= as.Date("2017-08-01") & date <= as.Date("2018-05-01") ~ NA_real_,
          date %in% as.Date(c("2020-12-01", "2022-10-01", "2023-03-01", "2023-10-01", "2024-05-01", "2024-10-01", "2025-02-01", "2026-02-01")) ~ NA_real_,
          TRUE ~ percentage
        )
      },
      smoothed_percentage = if (sum(!is.na(clean_percentage)) >= 2) {
        na.approx(clean_percentage, na.rm = FALSE)
      } else {
        clean_percentage
      },
      true_change = smoothed_percentage - lag(smoothed_percentage)
    ) %>%
    ungroup()
  
  # ----------------------------------------
  # [圖表 A]：基礎圖表實例化 (套用 UI 設定檔)
  # ----------------------------------------
  p_trend <- plot_data %>%
    drop_na(smoothed_percentage) %>% 
    ggplot(aes(x = date, y = smoothed_percentage, color = name)) +
    geom_line(linewidth = 1) + 
    theme_minimal(base_size = ui_config$base_size, base_family = ui_config$font_family) +      
    labs(
      title = paste("Steam 軟硬體歷史趨勢：", target_category),
      subtitle = "已修正抽樣異常與雜訊",
      x = "年份", y = "市佔率", color = "項目名稱"
    ) +
    # 【修改重點 1】：將 Y 軸的頂部緩衝區擴大至 0.5。
    # 這等同於將畫布上半部騰出一半的絕對空間，專門用來容納被物理引擎垂直推高的標籤。
    scale_y_continuous(labels = percent_format(accuracy = 1), expand = expansion(mult = c(0, 0.2))) +
    scale_x_date(date_breaks = "2 years", date_labels = "%Y") +
    
    theme(
      plot.title = element_text(face = "bold", size = ui_config$title_size),       
      plot.subtitle = element_text(size = ui_config$subtitle_size, color = ui_config$color_normal),
      axis.title = element_text(face = "bold", size = ui_config$axis_title_size),       
      axis.text = element_text(size = ui_config$axis_text_size),                       
      legend.title = element_text(face = "bold", size = ui_config$legend_title_size),     
      legend.text = element_text(size = ui_config$legend_text_size)                      
    )
  
  y_max <- max(plot_data$smoothed_percentage, na.rm = TRUE)
  if (is.infinite(y_max) || is.na(y_max)) y_max <- 0.3 
  
  # 【運算】：將讀取到的全域比例，乘上該圖表的實際極值，轉換為 Y 軸的絕對物理位移量
  current_nudge <- y_max * ui_config$nudge_ratio
  
  # ----------------------------------------
  # [特例預先渲染層] (套用 UI 設定檔)
  # ----------------------------------------
  if (target_category %in% c("Video Card Description", "VRAM")) {
    shadow_label <- paste0("礦潮停滯期\n(", if(target_category=="VRAM") "VRAM" else "玩家", "升級凍結)")
    p_trend <- p_trend +
      annotate("rect", xmin = as.Date("2020-09-17"), xmax = as.Date("2022-09-15"), ymin = -Inf, ymax = Inf, fill = ui_config$color_normal, alpha = 0.15) +
      annotate("text", x = as.Date("2021-09-15"), y = y_max * 0.95, label = shadow_label, 
               color = ui_config$color_normal, fontface = "italic", size = ui_config$watermark_size, alpha = 0.6, family = ui_config$font_family)
  }
  
  if (target_category == "Language") {
    anomaly_data <- plot_data %>% 
      filter(name == "Simplified Chinese" & date %in% as.Date(c("2017-10-01", "2018-02-01", "2021-08-01", "2022-10-01", "2023-10-01", "2024-10-01", "2025-02-01")))
    p_trend <- p_trend +
      geom_vline(data = anomaly_data, aes(xintercept = date), color = ui_config$color_alert, linetype = "dotted", linewidth = 0.6, alpha = 0.5) +
      geom_point(data = anomaly_data, aes(x = date, y = percentage), color = ui_config$color_alert, size = 3, shape = 21, fill = "white", stroke = 1.5)
  }
  
  # ----------------------------------------
  # [統一渲染管線] (套用 UI 設定檔)
  # ----------------------------------------
  events <- event_dict[[target_category]]
  
  if (!is.null(events)) {
    min_date <- min(plot_data$date, na.rm = TRUE)
    max_date <- max(plot_data$date, na.rm = TRUE)
    safe_events <- events %>% filter(date >= min_date & date <= max_date)
    
    if (nrow(safe_events) > 0) {
      normal_events <- safe_events %>% filter(line_type == "normal")
      alert_events <- safe_events %>% filter(line_type == "alert")
      
      if (nrow(normal_events) > 0) {
        p_trend <- p_trend + geom_vline(data = normal_events, aes(xintercept = date), color = ui_config$color_normal, linetype = "dashed", linewidth = 0.6, alpha = 0.8)
      }
      if (nrow(alert_events) > 0) {
        p_trend <- p_trend + geom_vline(data = alert_events, aes(xintercept = date), color = ui_config$color_alert, linetype = "dashed", linewidth = 0.7, alpha = 0.8)
      }
      
      # ----------------------------------------
      # 物理碰撞標籤引擎 (智能避讓 + 高能見度輔助線版)
      # ----------------------------------------
      # ----------------------------------------
      # 物理碰撞標籤引擎 (智能避讓 + 高能見度輔助線版)
      # ----------------------------------------
      p_trend <- p_trend + geom_label_repel(
        data = safe_events, 
        aes(x = date, y = y_max, label = paste0(format(date, "%Y-%m-%d"), "\n", label)),
        
        # 【渲染】：將剛才算出的動態絕對位移量，作為物理剛體的初始推力
        nudge_y = current_nudge,              
        
        direction = "both", 
        box.padding = 0.5,        
        point.padding = 0.5,      
        force = 5,                
        max.overlaps = Inf,       
        min.segment.length = 0,   
        
        hjust = 0.5, 
        segment.color = ui_config$segment_color, 
        segment.linetype = ui_config$segment_linetype,
        segment.size = ui_config$segment_linewidth, 
        fill = alpha("white", 0.8), 
        color = ui_config$color_text, 
        family = ui_config$font_family, 
        size = ui_config$label_size, 
        fontface = "bold",
        inherit.aes = FALSE      
      ) +
        coord_cartesian(clip = "off") + 
        theme(plot.margin = margin(t = 90, r = 30, b = 10, l = 30))
    }
  }
  
  # ----------------------------------------
  # [圖表 B]：歷史單月爆發力 Top 5 長條圖 (套用 UI 設定檔)
  # ----------------------------------------
  momentum_data <- plot_data %>%
    filter(!is.na(true_change)) %>%
    group_by(name) %>%
    slice_max(order_by = true_change, n = 1, with_ties = FALSE) %>%
    ungroup() %>%
    slice_max(order_by = true_change, n = 5, with_ties = FALSE) %>%
    mutate(
      event_label = reorder(paste0(name, "\n(", format(date, "%Y-%m"), ")"), true_change)
    )
  
  p_change <- ggplot(data = momentum_data, aes(x = true_change, y = event_label, fill = name)) +
    geom_col(width = 0.7) + 
    geom_text(
      aes(label = percent(true_change, accuracy = 0.1)), 
      hjust = -0.2, family = ui_config$font_family, size = ui_config$label_size, fontface = "bold"
    ) +
    theme_minimal(base_size = ui_config$base_size, base_family = ui_config$font_family) +      
    theme(
      legend.position = "none", 
      axis.text.y = element_text(face = "bold", size = ui_config$axis_text_size, color = ui_config$color_text),
      axis.title.x = element_text(face = "bold", size = ui_config$axis_title_size),
      plot.title = element_text(face = "bold", size = ui_config$title_size),
      plot.subtitle = element_text(size = ui_config$subtitle_size, color = ui_config$color_normal),
      plot.margin = margin(t = 10, r = 60, b = 10, l = 10) 
    ) + 
    labs(
      title = paste("Steam 軟硬體歷史單月爆發力 Top 5：", target_category),
      subtitle = "各項目歷史最高單月增長率事件 (已排除抽樣異常)",
      x = "單月最高變化百分比 (Max MoM Change)", y = NULL
    ) +
    scale_x_continuous(labels = percent_format(accuracy = 0.1), expand = expansion(mult = c(0, 0.15)))
  
  return(list(trend = p_trend, change = p_change))
}

# ==========================================
# 4. 批次檢視與輸出所有圖表
# ==========================================
target_categories <- c(
  "OS Version", "System RAM", "Intel CPU Speeds", "Physical CPUs", 
  "Video Card Description", "VRAM", "Primary Display Resolution", 
  "Multi-Monitor Desktop Resolution", "Language", "Total Hard Drive Space"
)

all_plots <- lapply(target_categories, function(cat) {
  generate_category_plots(dataset = df_shs, target_category = cat)
})
names(all_plots) <- target_categories

walk(names(all_plots), ~ {
  cat(sprintf("\n========== 正在渲染類別: %s ==========\n", .x))
  plots <- all_plots[[.x]]
  if (!is.null(plots)) {
    if (!is.null(plots$trend)) print(plots$trend)
    if (!is.null(plots$change)) print(plots$change)
  } else {
    warning(sprintf("跳過 %s：圖表物件為空 (NULL)。", .x))
  }
})
export_steam_charts(plot_list = all_plots)