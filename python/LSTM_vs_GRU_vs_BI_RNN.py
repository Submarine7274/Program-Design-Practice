import torch
import torch.nn as nn
import numpy as np
import matplotlib.pyplot as plt
import time
# 固定隨機種子
torch.manual_seed(777)
np.random.seed(777)
# 1. 超參數設定
input_size = 1
hidden_size = 6
output_size = 3 # 分類結果: 0, 1, 2
sequence_length = 20
num_epochs = 10 # 刻意設定較短的回合數，觀察收斂速度
learning_rate = 0.01
batch_size = 32
# 2. 產生實驗資料
def generate_comparison_data(num_samples, seq_len):
    X = np.zeros((num_samples, seq_len, 1), dtype=np.float32)
    clues = np.random.choice([1, 2], size=num_samples)
    X[:, 0, 0] = clues # t=0 的過去線索
    X[:, -1, 0] = 1 # t=19 的未來線索
    y = clues.astype(np.int64) # 正確答案
    return torch.tensor(X), torch.tensor(y)
X_train, y_train = generate_comparison_data(300, sequence_length)
X_test, y_test = generate_comparison_data(50, sequence_length)
# 3. 定義三種經典模型架構
class LSTMModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.lstm = nn.LSTM(input_size, hidden_size, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)
    def forward(self, x):
        out, _ = self.lstm(x)
        return self.fc(out[:, 10, :]) # 在 t=10 做出預測

class GRUModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.gru = nn.GRU(input_size, hidden_size, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)
    def forward(self, x):
        out, _ = self.gru(x)
        return self.fc(out[:, 10, :]) # 在 t=10 做出預測

class BiRNNModel(nn.Module):
    def __init__(self):
        super().__init__()
        # 雙向 RNN (這裡使用雙向 LSTM 作為代表)
        self.birlstm = nn.LSTM(input_size, hidden_size, batch_first=True, bidirectional=True)
        self.fc = nn.Linear(hidden_size * 2, output_size)
    def forward(self, x):
        out, _ = self.birlstm(x)
        return self.fc(out[:, 10, :]) # 在 t=10 做出預測(融合了雙向特徵)
# 初始化模型、損失函數
models = {'LSTM': LSTMModel(), 'GRU': GRUModel(), 'Bi-directional RNN': BiRNNModel()}
criterion = nn.CrossEntropyLoss()
# 4. 統一訓練迴圈並記錄 Loss 歷史
loss_histories = {}
train_times = {}
for name, model in models.items():
    optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)
    history = []
    start_time = time.time()
    for epoch in range(num_epochs):
        model.train()
        # 簡易批次訓練
        permutation = torch.randperm(X_train.size(0))
        epoch_loss = 0.0
        num_batches = 0
        for i in range(0, X_train.size(0), batch_size):
            indices = permutation[i:i+batch_size]
            batch_x, batch_y = X_train[indices], y_train[indices]
            outputs = model(batch_x)
            loss = criterion(outputs, batch_y)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
            epoch_loss += loss.item()
            num_batches += 1
        history.append(epoch_loss / max(1, num_batches))
    train_times[name] = time.time() - start_time
    loss_histories[name] = history
    # 計算測試集準確率
    model.eval()
    with torch.no_grad():
        test_preds = torch.argmax(model(X_test), dim=1)
        accuracy = (test_preds == y_test).float().mean().item() * 100
    print(f"【{name}】 訓練耗時: {train_times[name]:.3f} 秒 | 測試集準確率: {accuracy:.1f}%")
# 5. 繪製對比圖表
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))
# 圖一：訓練損失收斂曲線對比
colors = {'LSTM': '#4e79a7', 'GRU': '#f28e2b', 'Bi-directional RNN': '#e15759'}
for name, history in loss_histories.items():
    ax1.plot(history, label=f'{name} (Time: {train_times[name]:.2f}s)', color=colors[name], linewidth=2.5)
ax1.set_title('Training Loss Convergence Comparison', fontsize=14, fontweight='bold')
ax1.set_xlabel('Epochs', fontsize=12)
ax1.set_ylabel('Loss', fontsize=12)
ax1.grid(True, linestyle='--', alpha=0.5)
ax1.legend(fontsize=11)
# 圖二：最終測試集準確率柱狀圖
accuracies = []
model_names = list(models.keys())
for name in model_names:
    models[name].eval()
    with torch.no_grad():
        preds = torch.argmax(models[name](X_test), dim=1)
        acc = (preds == y_test).float().mean().item() * 100
    accuracies.append(acc)
bars = ax2.bar(model_names, accuracies, color=[colors[n] for n in model_names], width=0.5)
ax2.set_title('Final Test Accuracy on Context-Aware Task', fontsize=14, fontweight='bold')
ax2.set_ylabel('Accuracy (%)', fontsize=12)
ax2.set_ylim(0, 110)
ax2.grid(True, linestyle=':', alpha=0.5, axis='y')
# 在柱狀圖上標註數據
for bar in bars:
    yval = bar.get_height()
    ax2.text(bar.get_x() + bar.get_width()/2.0, yval + 2, f'{yval:.1f}%', ha='center', va='bottom', fontsize=12, fontweight='bold')
plt.tight_layout()
plt.show()