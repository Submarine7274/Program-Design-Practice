import torch
import torch.nn as nn
import math
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
class PositionalEncoding(nn.Module):
    def __init__(self, d_model, max_len=100):
        """
        d_model: 字詞向量的總維度 (必須是偶數)
        max_len: 句子允許的最大長度 (例如最多 100 個單字)
        """
        super(PositionalEncoding, self).__init__()
        # 1. 初始化一個全為 0 的位置編碼矩陣 (Shape: max_len, d_model)
        pe = torch.zeros(max_len, d_model)
        # 2. 生成位置序列向量 pos: [0, 1, 2, ..., max_len-1]，形狀轉為 (max_len, 1)
        position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
        # 3. 計算分母中的縮放項 (div_term)，利用 log 與 exp 來做矩陣優化加速計算
        # 2i 代表偶數維度，這裡只取一半的長度 (d_model // 2)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-math.log(10000.0) / d_model))
        # 4. 根據公式填充矩陣
        # 偶數維度 (0, 2, 4, ...) 使用正弦函數 sin
        pe[:, 0::2] = torch.sin(position * div_term)
        # 奇數維度 (1, 3, 5, ...) 使用餘弦函數 cos
        pe[:, 1::2] = torch.cos(position * div_term)
        # 5. 增加一個 Batch 維度 (Shape 變成: 1, max_len, d_model)，並註冊為模型 buffer (不參與梯度更新)
        self.register_buffer('pe', pe.unsqueeze(0))

    def forward(self, x):
        """
        x 是已經過 Embedding 後的字詞向量，Shape 為 (Batch_Size, Seq_Len, d_model)
        """
        # 將對應長度的位置編碼「加」到輸入向量上
        x = x + self.pe[:, :x.size(1)]
        return x
# --- 範例模擬執行 ---
# 假設我們有一句話，最大允許長度 max_len = 10，字詞特徵維度 d_model =
4
max_len = 10
d_model = 4
# 實例化位置編碼模組
pos_encoder = PositionalEncoding(d_model=d_model, max_len=max_len)
# 提取內部計算完畢的位置編碼矩陣 (移除 batch 維度，取出 10x4 的矩陣)
pe_matrix = pos_encoder.pe.squeeze(0).numpy()
# 打印前 4 個位置的位置編碼數值
print(f"=== 位置編碼矩陣結果 (展示前 4 個字的位置向量，維度為{d_model}) ===")
for pos in range(4):
    print(f"位置 {pos} (第 {pos+1} 個字) -> {pe_matrix[pos]}")

# 1. 依照論文公式建立位置編碼矩陣
max_len = 100
d_model = 64
pe = torch.zeros(max_len, d_model)
position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-math.log(10000.0) / d_model))
pe[:, 0::2] = torch.sin(position * div_term)
pe[:, 1::2] = torch.cos(position * div_term)
pe_matrix = pe.numpy()
# 2. 開始繪圖 (設定畫布大小)
plt.figure(figsize=(14, 5))
# --- 左圖：位置編碼熱圖 (Heatmap) ---
plt.subplot(1, 2, 1)
# 使用 seaborn 繪製矩陣熱圖
sns.heatmap(pe_matrix, cmap='RdBu', center=0, cbar_kws={'label': 'Value'})
plt.title("Positional Encoding Heatmap", fontsize=14)
plt.xlabel("Embedding Dimension (i)", fontsize=12)
plt.ylabel("Token Position (pos)", fontsize=12)
# --- 右圖：不同維度的波形圖 (Waveforms) ---
plt.subplot(1, 2, 2)
# 我們挑選第 0, 1, 2, 3 這四個不同頻率的特徵維度來觀察隨著位置變化的波形
plt.plot(pe_matrix[:, 0], label="Dim 0 (Sin, High Freq)", color='#1f77b4', linewidth=2)
plt.plot(pe_matrix[:, 1], label="Dim 1 (Cos, High Freq)", color='#aec7e8', linewidth=1.5)
plt.plot(pe_matrix[:, 8], label="Dim 8 (Sin, Mid Freq)", color='#ff7f0e', linewidth=2)
plt.plot(pe_matrix[:, 24], label="Dim 24 (Sin, Low Freq)", color='#2ca02c', linewidth=2)
plt.title("Sine & Cosine Waveforms by Dimension", fontsize=14)
plt.xlabel("Token Position (pos)", fontsize=12)
plt.ylabel("Encoding Value", fontsize=12)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(loc="upper right")
plt.tight_layout()
plt.show()