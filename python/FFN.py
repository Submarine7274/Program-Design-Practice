import torch
import torch.nn as nn
class PositionWiseFeedForward(nn.Module):
    def __init__(self, d_model, d_ff):
        super(PositionWiseFeedForward, self).__init__()
        # 第一層線性轉換：從 d_model 升維到 d_ff (通常是 4 倍)
        self.w_1 = nn.Linear(d_model, d_ff)
        # 第二層線性轉換：從 d_ff 降維回 d_model
        self.w_2 = nn.Linear(d_ff, d_model)
        # 激活函數
        self.activation = nn.ReLU()
    def forward(self, x):
        # x 的形狀: (batch_size, seq_len, d_model)
        # 步驟 1 & 2: 升維並通過激活函數
        hidden = self.activation(self.w_1(x))
        # 步驟 3: 降維輸出
        output = self.w_2(hidden)
        return output, hidden   
# --- 範例模擬執行 ---
torch.manual_seed(123) # 固定隨機種子
# 模擬一個句子: "AI is good" (長度為 3)，每個字的特徵維度 d_model = 4
# 矩陣形狀: (batch_size=1, seq_len=3, d_model=4)
sentence_tensor = torch.tensor([
[2.0, -1.0, 0.5, 1.5], # "AI" 的向量
[0.1, 1.2, -0.8, 2.0], # "is" 的向量
[-1.5, 0.5, 3.0, -0.2] # "good" 的向量
], dtype=torch.float32)
# 初始化 FFN：輸入維度 4，中間層擴展到 16 維
ffn_layer = PositionWiseFeedForward(d_model=4, d_ff=16)
# 前向傳播 (得到最終輸出與中間巨大隱藏層的狀態)
final_output, middle_hidden = ffn_layer(sentence_tensor)
# 打印數值結果來觀察特徵的變化
print("=== 1. 原始輸入向量 ('AI' 這個字) ===")
print(sentence_tensor[0, 0].numpy())
print("\n=== 2. 中間隱藏層向量 (升維到 16 維後的『AI』) ===")
# 觀察這 16 維中是不是有很多被 ReLU 歸零的特徵
print(middle_hidden[0, 0].detach().numpy())
print("\n=== 3. 最終輸出向量 (壓回 4 維後的『AI』) ===")
print(final_output[0, 0].detach().numpy())