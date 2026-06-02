import torch
import torch.nn as nn
# 1. 模擬一個 4x4 的單通道特徵圖 (Batch_size=1, Channel=1, Height=4, Width=4)
# 我們故意在矩陣中放置幾個「高分特徵點」(例如 8.0 和 9.0)，其餘為低分
feature_map = torch.tensor([[[
[1.0, 3.0, 8.0, 5.0],
[2.0, 4.0, 6.0, 7.0],
[0.0, 1.0, 9.0, 4.0],
[3.0, 2.0, 5.0, 6.0]
]]], dtype=torch.float32)
print("--- 1. 原始 4x4 特徵圖 (輸入) ---")
print(feature_map.squeeze())
print(f"輸入形狀 (Shape): {feature_map.shape}\n")
print("我們將這個 4x4 網格切分為四個 2x2 的獨立區域：")
print("左上:[1,3,2,4] | 右上:[8,5,6,7]")
print("左下:[0,1,3,2] | 右下:[9,4,5,6]\n")
print("="*60 + "\n")
# 2. 定義最大池化層 (Max Pooling)
# kernel_size=2 (窗口大小 2x2), stride=2 (步長為 2，代表窗口不重疊滑動)
max_pool = nn.MaxPool2d(kernel_size=2, stride=2)
# 3. 定義平均池化層 (Average Pooling)
avg_pool = nn.AvgPool2d(kernel_size=2, stride=2)
# 4. 執行池化轉換(下採樣)
max_output = max_pool(feature_map)
avg_output = avg_pool(feature_map)
# 5. 輸出結果展示
print("--- 2. 最大池化 (Max Pooling) 轉換結果 ---")
print(max_output.squeeze().detach())
print(f"輸出形狀 (Shape): {max_output.shape}")
print("技術解析：每個 2x2 區域中「最大」的特徵訊號被濃縮保留了下來(如右上角保留了 8.0)。\n")
print("--- 3. 平均池化 (Average Pooling) 轉換結果 ---")
print(avg_output.squeeze().detach())
print(f"輸出形狀 (Shape): {avg_output.shape}")
print("技術解析：每個 2x2 區域內的所有數值被加總平穩求平均(如左上角: (1+3+2+4)/4 = 2.5)。\n")