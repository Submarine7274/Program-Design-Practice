import torch
import torch.nn as nn
# 設定隨機種子以確保每次執行結果相同
torch.manual_seed(42)
# 1. 模擬經過卷積與池化後提取出的「特徵圖 (Feature Map)」
# 假設特徵圖尺寸為 (Batch_size=1, Channels=2, Height=2, Width=2)
# 這代表有 2 個特徵通道，每個通道大小為 2x2
feature_map = torch.tensor([[[
[1.5, 0.5],
[0.0, 2.0]
], [
[0.1, 1.2],
[3.0, 0.2]
]]], dtype=torch.float32)
print("--- 1. 卷積/池化層輸出後的立體特徵圖 ---")
print(f"特徵圖形狀 (Shape): {feature_map.shape}")
print(f"通道 1 (例如耳朵特徵):\n{feature_map[0, 0]}")
print(f"通道 2 (例如尾巴特徵):\n{feature_map[0, 1]}\n")
# 2. 技術步驟一：展平 (Flatten)
# 將多維的特徵圖拉直成一維向量，準備輸入全連接層
flatten_layer = nn.Flatten()
flattened_vector = flatten_layer(feature_map)
print("--- 2. 經過 Flatten 轉換後的一維特徵向量 ---")
print(flattened_vector)
print(f"特徵向量長度: {flattened_vector.shape[1]} (即 2通道 * 2高 * 2寬 = 8)\n")
print("="*60 + "\n")
# 3. 技術步驟二：全連接層 (Fully Connected Layer)
# 輸入特徵長度為 8，我們想要分類 2 個類別 (類別 0: 貓, 類別 1: 狗)
# nn.Linear 內部會自動建立一個 2x8 的權重矩陣 (W) 與長度為 2 的偏差向量 (B)
fc_layer = nn.Linear(in_features=8, out_features=2)
# 4. 前向傳播：計算線性加權組合 Z = XW + B (輸出原始分數 Logits)
logits = fc_layer(flattened_vector)
print("--- 3. 全連接層輸出的原始分數 (Logits) ---")
print(logits.detach())
print("說明：此時的分數是任意實數，還無法直觀代表概率。\n")
# 5. 技術步驟三：Softmax 概率轉換
# dim=-1 代表在最後一個維度(類別維度)上進行歸一化
softmax = nn.Softmax(dim=-1)
probabilities = softmax(logits)
print("--- 4. 經過 Softmax 轉換後的最終分類概率 ---")
print(probabilities.detach())
print(f"貓的概率: {probabilities[0, 0].item()*100:.2f}%")
print(f"狗的概率: {probabilities[0, 1].item()*100:.2f}%")
print(f"兩者概率相加: {torch.sum(probabilities).item()} (必定為 1.0)")