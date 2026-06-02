import torch
import torch.nn as nn
# 1. 模擬一張獨熱(One-hot)的虛擬圖片 (Batch_size, Channels, Height, Width)
# 假設這是一張 5x5 的灰階圖片，中間有一個「十」字型的白色線條(數值為 1.0)
input_image = torch.tensor([[[
[0.0, 0.0, 1.0, 0.0, 0.0],
[0.0, 0.0, 1.0, 0.0, 0.0],
[1.0, 1.0, 1.0, 1.0, 1.0],
[0.0, 0.0, 1.0, 0.0, 0.0],
[0.0, 0.0, 1.0, 0.0, 0.0]
]]], dtype=torch.float32)
print("--- 原始 5x5 圖片輸入 ---")
print(input_image.squeeze()) # squeeze() 用來去掉多餘的維度方便列印
print(f"輸入形狀 (Shape): {input_image.shape}\n")
# 2. 定義一個卷積層 (建立局部感受域)
# 輸入通道=1, 輸出通道=1, 卷積核(感受域)大小=3x3, 步長(Stride)=1, 不補零(Padding=0 超出的範圍要不要補零)
conv_layer = nn.Conv2d(in_channels=1, out_channels=1, kernel_size=3, stride=1, padding=0, bias=False)
# 3. 手動設定卷積核的權重(模擬一個專門偵測「垂直線」的濾鏡)
# 這個 3x3 的垂直濾鏡，中間那行權重較高
vertical_filter = torch.tensor([[[
[-1.0, 2.0, -1.0],
[-1.0, 2.0, -1.0],
[-1.0, 2.0, -1.0]
]]], dtype=torch.float32)
# 將我們自訂的權重強行賦予給 PyTorch 的卷積層
conv_layer.weight.data = vertical_filter
print("--- 自訂的 3x3 卷積核 (局部感受域大小) ---")
print(conv_layer.weight.data.squeeze())
print("\n" + "="*40 + "\n")
# 4. 前向傳播：讓局部感受域在圖片上滑動計算
output_feature_map = conv_layer(input_image)
print("--- 卷積運算後輸出的特徵圖 (Feature Map) ---")
print(output_feature_map.squeeze().detach())
print(f"輸出形狀 (Shape): {output_feature_map.shape}\n")