import torch
import torch.nn as nn
# 1. 建立一個 5x5 的灰階圖片 (Batch_size=1, Channel=1, Height=5, Width=5)
# 我們在中間設計一條垂直的「白線」(數值為 1.0)，其餘為黑(0.0)
input_image = torch.tensor([[[
[0.0, 0.0, 1.0, 0.0, 0.0],
[0.0, 0.0, 1.0, 0.0, 0.0],
[0.0, 0.0, 1.0, 0.0, 0.0],
[0.0, 0.0, 1.0, 0.0, 0.0],
[0.0, 0.0, 1.0, 0.0, 0.0]
]]], dtype=torch.float32)
print("--- 1. 原始 5x5 輸入圖片 ---")
print(input_image.squeeze())
print(f"輸入形狀: {input_image.shape}\n")
# 2. 定義卷積層
# 設定：Kernel_size=3, Stride=1, Padding=0 (不補零)
conv_layer = nn.Conv2d(in_channels=1, out_channels=1, kernel_size=3, stride=1, padding=0, bias=False)
# 3. 手動設定卷積核的權重(設計一個專門偵測「垂直邊緣」的索貝爾濾鏡 Sobel Filter)
# 這種濾鏡中間權重高、兩側權重低且為負數，能強烈對比出垂直線條
vertical_filter = torch.tensor([[[
[-1.0, 2.0, -1.0],
[-1.0, 2.0, -1.0],
[-1.0, 2.0, -1.0]
]]], dtype=torch.float32)
conv_layer.weight.data = vertical_filter
print("--- 2. 自訂的 3x3 卷積核 (垂直特徵提取器) ---")
print(conv_layer.weight.data.squeeze())
print("\n" + "="*50 + "\n")
# 4. 進行卷積轉換(前向傳播)
output_feature_map = conv_layer(input_image)
print("--- 3. 卷積運算後輸出的特徵圖 (Feature Map) ---")
print(output_feature_map.squeeze().detach())
print(f"輸出形狀: {output_feature_map.shape}\n")