import torch
import torch.nn as nn
import torch.nn.functional as F
# 定義簡單的自注意力層
class RealSelfAttention(nn.Module):
    def __init__(self, embed_dim):
            super(RealSelfAttention, self).__init__()
            self.embed_dim = embed_dim
            # 轉換成 Q, K, V 的三個權重矩陣
            self.q_linear = nn.Linear(embed_dim, embed_dim, bias=False)
            self.k_linear = nn.Linear(embed_dim, embed_dim, bias=False)
            self.v_linear = nn.Linear(embed_dim, embed_dim, bias=False)

    def forward(self, x):
            # x 的形狀: (batch_size, seq_len, embed_dim)
            batch_size, seq_len, embed_dim = x.size()
            # 1. 計算 Q, K, V 向量
            Q = self.q_linear(x)
            K = self.k_linear(x)
            V = self.v_linear(x)
            # 2. 計算相似度分數 (Dot-Product)
            # K.transpose(-2, -1) 是為了將 K 矩陣轉置以進行矩陣乘法
            scores = torch.matmul(Q, K.transpose(-2, -1))
            # 3. 縮放分數 (Scaling)
            d_k = embed_dim
            scaled_scores = scores / (d_k ** 0.5)
            # 4. 透過 Softmax 得到歸一化的注意力權重 (Attention Weights)
            attention_weights = F.softmax(scaled_scores, dim=-1)
            # 5. 權重與 Value 進行加權總和
            output = torch.matmul(attention_weights, V)
            return output, attention_weights
# --- 範例模擬執行 ---
torch.manual_seed(42) # 固定隨機種子以確保結果可重現
# 假設輸入一個句子: "I love AI" (長度為 3)，每個單字的字詞向量維度為 4
# 形狀為 (batch_size=1, seq_len=3, embed_dim=4)
sentence_embedding = torch.randn(1, 3, 4)
# 初始化我們的自注意力層
attention_layer = RealSelfAttention(embed_dim=4)
# 執行前向傳播
output_vectors, attn_weights = attention_layer(sentence_embedding)
# 打印結果
print("=== 1. 注意力權重矩陣 (Attention Weights) ===")
# 移除 batch 維度方便觀察
weights = attn_weights.squeeze(0).detach().numpy()
print(weights)
print("\n=== 2. 經過注意力機制加工後的輸出向量 ===")
print(output_vectors.squeeze(0).detach().numpy())