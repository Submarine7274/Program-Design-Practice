import torch
import torch.nn as nn
import torch.nn.functional as F
import math
# 1. 位置編碼 (Positional Encoding) 實作
class PositionalEncoding(nn.Module):
    def __init__(self, d_model, max_len=20):
        super(PositionalEncoding, self).__init__()
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-math.log(10000.0) / d_model))
        pe[:, 0::2] = torch.sin(position * div_term)
        pe[:, 1::2] = torch.cos(position * div_term)
        self.register_buffer('pe', pe.unsqueeze(0))
    def forward(self, x):
    # x shape: [batch_size, seq_len, d_model]
        return x + self.pe[:, :x.size(1)]
    # 2. 多頭注意力與前饋網路(完整 Encoder Layer)
class TransformerEncoderLayer(nn.Module):
    def __init__(self, d_model, nhead, d_ff):
        super(TransformerEncoderLayer, self).__init__()
        self.head_dim = d_model // nhead
        self.nhead = nhead
        # 多頭注意力的線性映射
        self.q_linear = nn.Linear(d_model, d_model, bias=False)
        self.k_linear = nn.Linear(d_model, d_model, bias=False)
        self.v_linear = nn.Linear(d_model, d_model, bias=False)
        self.out_linear = nn.Linear(d_model, d_model, bias=False)
        # Add & Norm 層
        self.norm1 = nn.LayerNorm(d_model)
        self.norm2 = nn.LayerNorm(d_model)
        # 前饋神經網路 (FFN)
        self.ffn = nn.Sequential(
        nn.Linear(d_model, d_ff),
        nn.ReLU(),
        nn.Linear(d_ff, d_model)
        )
def forward(self, x):
# --- Multi-Head Attention 子層 ---
    b, seq_len, d_model = x.size()
    Q = self.q_linear(x).view(b, seq_len, self.nhead, self.head_dim).transpose(1, 2)
    K = self.k_linear(x).view(b, seq_len, self.nhead, self.head_dim).transpose(1, 2)
    V = self.v_linear(x).view(b, seq_len, self.nhead, self.head_dim).transpose(1, 2)
    scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(self.head_dim)
    attn_weights = F.softmax(scores, dim=-1)
    context = torch.matmul(attn_weights, V).transpose(1, 2).contiguous().view(b, seq_len, d_model)
    attn_out = self.out_linear(context)
    # 殘差連接與層歸一化 (Add & Norm)
    x = self.norm1(x + attn_out)
    # --- FFN 子層 ---
    ffn_out = self.ffn(x)
    # 第二次 殘差連接與層歸一化 (Add & Norm)
    x = self.norm2(x + ffn_out)
    return x, attn_weights
# --- 模擬機器翻譯推論 ---
torch.manual_seed(42)
# 超參數設定
d_model = 8 # 字詞特徵維度
nhead = 2 # 2 個注意力頭
d_ff = 16 # FFN 中間層維度
# 模擬輸入句子: "I love AI" -> 通過 Embedding 層後長度為 3
src_embedding = torch.randn(1, 3, d_model)
# 實例化模組
pos_encoder = PositionalEncoding(d_model)
encoder_layer = TransformerEncoderLayer(d_model, nhead, d_ff)
# 執行 Transformer 計算流
x = pos_encoder(src_embedding)
output, attention_maps = encoder_layer(x)
print("=== Transformer 執行成功 ===")
print("最終輸出特徵矩陣形狀 (Batch, Seq_Len, Embed_Dim):", output.shape)
print("\n第一個字 'I' 經過全套 Transformer 加工後的特徵向量:\n", output[0, 0].detach().numpy())