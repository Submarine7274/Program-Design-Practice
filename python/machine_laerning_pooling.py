import torch
import torch.nn as nn
# 1. 建立一個 4x4 的特徵圖 (模擬卷積層輸出後、準備被池化的資料)
# 維度形狀同樣符合 PyTorch 規範: (Batch_size=1, Channel=1, Height=4, Width=4)
feature_map = torch.tensor([[[
[1.0, 3.0, 8.0, 5.0],
[2.0, 4.0, 6.0, 7.0],
[0.0, 1.0, 9.0, 4.0],
[3.0, 2.0, 5.0, 6.0]
]]], dtype=torch.float32)
print("--- 1. 原始 4x4 特徵圖 (輸入) ---")
print(feature_map.squeeze())
print(f"輸入形狀: {feature_map.shape}\n")
# 2. 定義最大池化層 (Max Pooling)
# kernel_size=2 (窗口 2x2), stride=2 (步長為 2，代表不重疊跳格滑動)
max_pool = nn.MaxPool2d(kernel_size=2, stride=2)
# 3. 定義平均池化層 (Average Pooling)
avg_pool = nn.AvgPool2d(kernel_size=2, stride=2)
# 4. 執行池化運算 (下採樣轉換)
max_output = max_pool(feature_map)
avg_output = avg_pool(feature_map)
print("="*50)
print("--- 2. 最大池化 (Max Pooling) 執行結果 ---")
print(max_output.squeeze().detach())
print(f"輸出形狀: {max_output.shape}")
print("說明：每個 2x2 區域只留下「最大」的值(例如第一區留下 4.0)。\n")
print("--- 3. 平均池化 (Average Pooling) 執行結果 ---")
print(avg_output.squeeze().detach())
print(f"輸出形狀: {avg_output.shape}")
print("說明：每個 2x2 區域計算「平均」值(例如第一區: (1+3+2+4)/4 = 2.5)。")
print("="*50)