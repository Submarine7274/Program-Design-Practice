import torch
import torch.nn as nn
# 設定隨機種子以利復現結果
torch.manual_seed(42)
# 1. 模擬一個 5x5 的單通道圖像 (Batch_size=1, Channel=1, Height=5, Width=5)
# 這裡填入連續數字，方便對照計算過程
input_image = torch.arange(1, 26, dtype=torch.float32).reshape(1, 1, 5, 5)
print("--- 1. 原始 5x5 輸入圖片 (每個數字代表一個像素值) ---")
print(input_image.squeeze())
print(f"輸入形狀: {input_image.shape}\n")
# 2. 定義一個 3x3 的卷積層
# 關閉 bias (偏差) 讓我們能純粹觀察權重的行為
conv_layer = nn.Conv2d(in_channels=1, out_channels=1, kernel_size=3, stride=1, padding=0, bias=False)
# 3. 列印這個卷積層的權重 (這就是被共享的「唯一一組」參數)
shared_weights = conv_layer.weight.data.squeeze()
print("--- 2. 這個卷積層內部的 3x3 核心權重 ---")
print(shared_weights)
print("請注意：接下來不論濾鏡滑動到哪裡，參與計算的都是這組完全相同的 9 個數字。\n")
print("="*60 + "\n")
# 4. 前向傳播：讓這個共享權重的濾鏡滑動掃描整張圖
output_feature_map = conv_layer(input_image)
print("--- 3. 輸出特徵圖 (Feature Map) ---")
print(output_feature_map.squeeze().detach())
print(f"輸出形狀: {output_feature_map.shape}\n")
# 5. 數學驗證說明「權重共享」如何發生
print("--- 4. 轉換過程的數學驗證(如何共享？) ---")
# 提取圖片左上角 3x3 區域
local_region_1 = input_image[0, 0, 0:3, 0:3]
# 提取圖片右下角 3x3 區域
local_region_2 = input_image[0, 0, 2:5, 2:5]
# 手動用同一組權重計算兩個不同位置的結果
calc_1 = torch.sum(local_region_1 * conv_layer.weight.data.squeeze())
calc_2 = torch.sum(local_region_2 * conv_layer.weight.data.squeeze())
print(f"位置 1 (左上角 3x3 矩陣) 與【該組權重】相乘求和 = {calc_1.item():.4f} (對應輸出左上角)")
print(f"位置 9 (右下角 3x3 矩陣) 與【同一組權重】相乘求和 = {calc_2.item():.4f} (對應輸出右下角)")