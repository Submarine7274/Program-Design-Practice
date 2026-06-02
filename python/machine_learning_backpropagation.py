import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt

# 1. 準備數據：y = 3x + 1，並加入一些雜訊
x = torch.linspace(-2, 2, 50).view(-1, 1)
y_true = 3 * x + 1 + torch.randn(x.size()) * 0.5

# 2. 定義模型
model = nn.Linear(1, 1)

# 3. 定義損失函數與優化器
criterion = nn.MSELoss()
optimizer = optim.SGD(model.parameters(), lr=0.1)

# 建立一個空列表，用來存放訓練過程中的歷史預測結果
historical_preds = []

# 4. 開始訓練
losses = []
for epoch in range(100):
    # 修改：將取餘數的條件改為 10
    # 這樣在 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 時各紀錄一次，精確取得 10 條線
    if epoch % 10 == 0:
        with torch.no_grad(): 
            historical_preds.append(model(x).clone())

    # --- 前向傳播 ---
    y_pred = model(x)
    loss = criterion(y_pred, y_true)
    losses.append(loss.item())

    # --- 反向傳播 ---
    optimizer.zero_grad() 
    loss.backward()       
    optimizer.step()      

# 紀錄訓練後的最終狀態
with torch.no_grad():
    y_trained = model(x)

# 5. 繪製圖表
plt.figure(figsize=(14, 5))

# 子圖 1：前向傳播 vs 真實數據
plt.subplot(1, 2, 1)
plt.scatter(x.numpy(), y_true.numpy(), color='gray', alpha=0.5, label='Actual Data')

# 迭代歷史預測結果並繪出 10 條漸進紅虛線
num_lines = len(historical_preds)
for i, pred in enumerate(historical_preds):
    # 透明度隨迭代次數加深
    alpha_val = 0.2 + 0.8 * (i / max(1, num_lines - 1))
    label_text = 'Training Process (Intermediate)' if i == 0 else ""
    plt.plot(x.numpy(), pred.numpy(), 'r--', alpha=alpha_val, label=label_text)

# 繪製最終訓練完成的綠線
plt.plot(x.numpy(), y_trained.numpy(), 'g-', linewidth=2, label='After Backpropagation (Learned)')
plt.title("Forward Pass: Training Progression")
plt.legend()

# 子圖 2：損失函數曲線
plt.subplot(1, 2, 2)
plt.plot(losses, color='blue')
plt.title("Loss Reduction via Backpropagation")
plt.xlabel("Epochs")
plt.ylabel("Loss (Error)")
plt.tight_layout()
plt.show()