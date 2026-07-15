import torch
import torch.nn as nn
# 固定隨機種子
torch.manual_seed(42)
# 1. 模擬輸入資料 (Batch Size = 2, 序列長度 Seq Len = 3, 嵌入維度 Embed Dim = 4)
# 可以想像成有 2 個句子，每個句子有 3 個字，每個字由 4 個數字(特徵)代表。
# 為了方便 BatchNorm 計算，我們調整 Shape 順序
# 形狀為: (Batch, Token_Position, Feature_Dimension)
input_tensor = torch.randn(2, 3, 4)
# 2. 定義 Layer Normalization (針對最後一個維度，即特徵維度 4 進行歸一化)
layer_norm = nn.LayerNorm(normalized_shape=4, elementwise_affine=False)
# 3. 定義 Batch Normalization (針對 Channel/Feature 維度進行縱向歸一化)
# 為了符合 PyTorch BatchNorm1d 的預期輸入 (Batch, Feature, Seq_Len)，我們需要轉置
batch_norm = nn.BatchNorm1d(num_features=4, affine=False)
# 4. 執行前向傳播
ln_output = layer_norm(input_tensor)
# BatchNorm 需要將 Feature 維度換到第二個維度
bn_input = input_tensor.transpose(1, 2)
bn_output = batch_norm(bn_input).transpose(1, 2) # 算完再轉回來方便對比
# 5. 打印測試成果 (以第一個句子的第一個單字為例)
print("=== 原始輸入向量 (第一個句子, 第一個單字) ===")
print(input_tensor[0, 0].numpy())
print("\n=== A. 經過 Layer Norm 處理後的向量 ===")
print(ln_output[0, 0].numpy())
print("\n=== B. 經過 Batch Norm 處理後的向量 ===")
print(bn_output[0, 0].numpy())