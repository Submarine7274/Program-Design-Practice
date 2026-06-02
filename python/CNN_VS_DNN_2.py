import torch
import torch.nn as nn
# 設定隨機種子確保結果可重現
torch.manual_seed(1)
# 1. 建立「原始圖片」與「平移後的圖片」 (假設是 1x1x5x5 的灰階圖)
# 原始圖片：特徵(數值 5.0)在左側第三列
image_original = torch.tensor([[[
[0.0, 0.0, 5.0, 0.0, 0.0],
[0.0, 0.0, 5.0, 0.0, 0.0],
[0.0, 0.0, 5.0, 0.0, 0.0],
[0.0, 0.0, 5.0, 0.0, 0.0],
[0.0, 0.0, 5.0, 0.0, 0.0]
]]], dtype=torch.float32)
# 平移圖片：將特徵向右移動 2 格，到了最右側
image_shifted = torch.tensor([[[
[0.0, 0.0, 0.0, 0.0, 5.0],
[0.0, 0.0, 0.0, 0.0, 5.0],
[0.0, 0.0, 0.0, 0.0, 5.0],
[0.0, 0.0, 0.0, 0.0, 5.0],
[0.0, 0.0, 0.0, 0.0, 5.0]
]]], dtype=torch.float32)
print("--- 原始圖片 ---")
print(image_original.squeeze())
print("--- 平移後的圖片 (特徵右移 2 格) ---")
print(image_shifted.squeeze())
print("\n" + "="*50 + "\n")
# =====================================================================
# 2. 測試傳統 DNN 模型
# =====================================================================
class SimpleDNN(nn.Module):
    def __init__(self):
        super().__init__()
        self.flatten = nn.Flatten()
        # 輸入 5x5=25 個節點，隱藏層 1 個節點(用來輸出對該特徵的敏感度)
        self.fc = nn.Linear(25, 1, bias=False)
    def forward(self, x):
        x = self.flatten(x)
        return self.fc(x)
dnn_model = SimpleDNN()
# 讓 DNN 學習原始圖片(手動給予權重，模擬它死記了這個位置)
# 只有在原始特徵對應的第 2 個索引位置給予高權重
dnn_weights = torch.zeros(1, 25)
dnn_weights[0, [2, 7, 12, 17, 22]] = 1.0 # 記住原始位置
dnn_model.fc.weight.data = dnn_weights
# =====================================================
# 3. 測試 CNN 模型
# =====================================================
class SimpleCNN(nn.Module):
    def __init__(self):
        super().__init__()
        # 使用 3x3 卷積核
        self.conv = nn.Conv2d(1, 1, kernel_size=3, padding=1, bias=False)
    def forward(self, x):
        return self.conv(x)
cnn_model = SimpleCNN()
# 讓 CNN 學習特徵(手動設定 3x3 濾鏡，中間給予高權重 1.0，代表它學會了垂直線特徵)
cnn_filter = torch.tensor([[[
[0.0, 1.0, 0.0],
[0.0, 1.0, 0.0],
[0.0, 1.0, 0.0]
]]], dtype=torch.float32)
cnn_model.conv.weight.data = cnn_filter
# ==============================================================
# 4. 執行對比測試(驗證平移不變性)
# ==============================================================
print("【 測試傳統 DNN 的反應 】")
dnn_score_orig = dnn_model(image_original).item()
dnn_score_shift = dnn_model(image_shifted).item()
print(f"面對原始圖片 -> 辨識特徵得分: {dnn_score_orig}")
print(f"面對平移圖片 -> 辨識特徵得分: {dnn_score_shift}")
print("結論：物體一移動，DNN 的得分直接歸零，完全認不出來！")
print("\n" + "-"*50 + "\n")
print("【 測試 CNN 的反應 】")
# 我們看 CNN 輸出特徵圖的最大值，代表有沒有在全圖某個角落抓到特徵
cnn_score_orig = torch.max(cnn_model(image_original)).item()
cnn_score_shift = torch.max(cnn_model(image_shifted)).item()
print(f"面對原始圖片 -> 局部最強特徵得分: {cnn_score_orig}")
print(f"面對平移圖片 -> 局部最強特徵得分: {cnn_score_shift}")
print("結論：不論特徵怎麼移動，CNN 的最強激發分數完全不變！完美認出！")