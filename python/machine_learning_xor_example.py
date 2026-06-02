import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
# 1. 建立 XOR 資料集
# 輸入 (x1, x2)，輸出 y
X = torch.tensor([[0,0], [0,1], [1,0], [1,1]], dtype=torch.float32)
Y = torch.tensor([[0], [1], [1], [0]], dtype=torch.float32)
# 2. 設計 MLP 架構
class XORModel(nn.Module):
    def __init__(self):
        super(XORModel, self).__init__()
        # 隱藏層：將 2 個輸入轉為 4 個特徵
        self.hidden = nn.Linear(2, 4)
        # 激活函數：引入非線性
        self.relu = nn.ReLU()
        # 輸出層：將 4 個特徵轉為 1 個輸出
        self.output = nn.Linear(4, 1)
        self.sigmoid = nn.Sigmoid()
    def forward(self, x):
        x = self.relu(self.hidden(x))
        x = self.sigmoid(self.output(x))
        return x
# 3. 初始化模型、損失函數與優化器
model = XORModel()
criterion = nn.BCELoss() # 二元交叉熵損失
optimizer = optim.SGD(model.parameters(), lr=0.1)
# 4. 訓練模型
for epoch in range(2000):
    optimizer.zero_grad()
    predictions = model(X)
    loss = criterion(predictions, Y)
    loss.backward()
    optimizer.step()
    if (epoch + 1) % 500 == 0:
        print(f"Epoch [{epoch+1}/2000], Loss: {loss.item():.4f}")
# 5. 測試結果
with torch.no_grad():
    test_output = model(X)
    predicted = (test_output > 0.5).float()
    print("\n最終預測結果:")
    for i in range(len(X)):
        print(f"輸入: {X[i].numpy()} -> 預測值: {test_output[i].item():.4f} -> 分類: {int(predicted[i])}")