import torch
import torch.nn as nn
import torch.nn.functional as F
class ExplicitMultiHeadAttention(nn.Module):
    def __init__(self, embed_dim, num_heads):
        super(ExplicitMultiHeadAttention, self).__init__()
        self.embed_dim = embed_dim
        self.num_heads = num_heads
        # 確保總維度可以被頭數整除
        assert embed_dim % num_heads == 0, "embed_dim 必須能被 num_heads 整除"
        self.head_dim = embed_dim // num_heads
        # 定義 Q, K, V 的線性變換層
        self.q_linear = nn.Linear(embed_dim, embed_dim, bias=False)
        self.k_linear = nn.Linear(embed_dim, embed_dim, bias=False)
        self.v_linear = nn.Linear(embed_dim, embed_dim, bias=False)
        # 最後的輸出線性整合層 (Wo)
        self.out_linear = nn.Linear(embed_dim, embed_dim, bias=False)
    def forward(self, x):
        batch_size, seq_len, embed_dim = x.size()
        # 1. 線性映射取得大 Q, K, V (Shape: batch, seq_len, embed_dim)
        Q_all = self.q_linear(x)
        K_all = self.k_linear(x)
        V_all = self.v_linear(x)
# 2. 切分成多個頭 (Split into Multi-Heads)
# 轉換形狀為: (batch, seq_len, num_heads, head_dim)
# 再轉置為: (batch, num_heads, seq_len, head_dim) 以便多頭平行計算
        Q = Q_all.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        K = K_all.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        V = V_all.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
# 3. 計算縮放點積注意力分數
        scores = torch.matmul(Q, K.transpose(-2, -1)) / (self.head_dim ** 0.5)
        attention_weights = F.softmax(scores, dim=-1)
# 4. 每個頭獨立進行加權總和 (Shape: batch, num_heads, seq_len,head_dim)
        head_outputs = torch.matmul(attention_weights, V)
# 5. 拼接所有頭的輸出 (Concatenate)
# 先轉置回 (batch, seq_len, num_heads, head_dim) 再用 view 攤平回原維度
        concat_output = head_outputs.transpose(1,2).contiguous().view(batch_size, seq_len, embed_dim)
# 6. 最後的線性整合轉換
        output = self.out_linear(concat_output)
        return output, attention_weights
# --- 範例模擬執行 ---
torch.manual_seed(42) # 固定隨機種子
# 模擬輸入句子: "蘋果 很大" (長度為 2)，每個字維度為 4
# 矩陣形狀: (batch_size=1, seq_len=2, embed_dim=4)
sentence_embedding = torch.randn(1, 2, 4)
# 初始化多頭注意力層：維度 4，拆成 2 個頭
mha_layer = ExplicitMultiHeadAttention(embed_dim=4, num_heads=2)
# 前向傳播
output_vectors, attn_weights = mha_layer(sentence_embedding)
# 提取兩個頭各自的注意力權重矩陣 (Shape: num_heads=2, seq_len=2,seq_len=2)
weights = attn_weights.squeeze(0).detach().numpy()
print("=== Head 1 注意力權重 ===")
print(weights[0])
print("\n=== Head 2 注意力權重 ===")
print(weights[1])