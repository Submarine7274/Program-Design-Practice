import torch
import torch.nn as nn
import numpy as np
import matplotlib.pyplot as plt
# 設定隨機種子
torch.manual_seed(42)
np.random.seed(42)
# 1. 超參數設定
input_size = 1 # 每個時間步輸入 1 個數字
hidden_size = 8 # 單向隱藏層神經元數量(雙向拼接後會變成 16)
output_size = 3 # 預測中間空格的分類：0, 1, 2
sequence_length = 21
num_epochs = 300
learning_rate = 0.01
# 2. 建立雙向上下文資料集
def generate_bidirectional_data(num_samples, seq_len):
    X = np.zeros((num_samples, seq_len, 1), dtype=np.float32)
    # 隨機決定兩端對齊的線索是 1 還是 2
    clues = np.random.choice([1, 2], size=num_samples)
    X[:, 0, 0] = clues # 開頭線索 (過去)
    X[:, -1, 0] = clues # 結尾線索 (未來)
    # 中間第 10 格 (索引 10) 保持為 0，作為我們要預測的空格
    y = clues.astype(np.int64) # 正確答案
    return torch.tensor(X), torch.tensor(y)
X_train, y_train = generate_bidirectional_data(200, sequence_length)
X_test, y_test = generate_bidirectional_data(10, sequence_length)
# 3. 定義雙向 LSTM 模型
class BiLSTMClassifier(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super(BiLSTMClassifier, self).__init__()
        # bidirectional=True 會同時建立正向與反向 LSTM
        self.lstm = nn.LSTM(input_size, hidden_size, batch_first=True, bidirectional=True)
        # 因為雙向會將兩層的隱藏狀態拼接，所以全連接層的輸入維度要乘以 2
        self.fc = nn.Linear(hidden_size * 2, output_size)
    def forward(self, x):
        # out 維度: (batch, seq_len, hidden_size * 2)
        out, (h_n, c_n) = self.lstm(x)
        # 我們要預測的是「中間第 10 格」填空，所以直接取出第 10個時間步的雙向融合特徵
        mid_feature = out[:, 10, :]
        out = self.fc(mid_feature)
        return out
model = BiLSTMClassifier(input_size, hidden_size, output_size)
criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)
# 4. 模型訓練
loss_history = []
print("開始訓練雙向 LSTM 模型...")
for epoch in range(num_epochs):
    model.train()
    outputs = model(X_train)
    loss = criterion(outputs, y_train)
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    loss_history.append(loss.item())
    if (epoch+1) % 50 == 0:
        print(f"Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}")
# 5. 模型評估
model.eval()
with torch.no_grad():
# 在 no_grad 區塊中執行推論
    test_outputs = model(X_test)
    predictions = torch.argmax(test_outputs, dim=1)
    accuracy = (predictions == y_test).float().mean()
    print(f"\n測試集準確率: {accuracy.item() * 100:.1f}%")
# 選擇一個測試樣本來視覺化
sample_idx = 4
sample_seq = X_test[sample_idx].numpy().flatten()
true_answer = y_test[sample_idx].item()
pred_answer = predictions[sample_idx].item()
time_steps = np.arange(sequence_length)
plt.figure(figsize=(14, 6))
# 繪製輸入序列
plt.plot(time_steps, sample_seq, color='#4a4e69', linewidth=1.5, linestyle=':', zorder=1)
plt.scatter(time_steps, sample_seq, color='#9a8c98', s=30, zorder=2)
# 強調關鍵點
plt.scatter([0], [sample_seq[0]], color='#e63946', s=180, zorder=5, label=f'Past Clue (t=0, Value: {int(sample_seq[0])})')
plt.scatter([20], [sample_seq[-1]], color='#457b9d', s=180, zorder=5, label=f'Future Clue (t=20, Value: {int(sample_seq[-1])})')
plt.scatter([10], [0], color='#2a9d8f', s=200, marker='X', zorder=5, label=f'Target Blank (t=10, Predict: {pred_answer})')
# 繪製雙向資訊流動箭頭
# 正向資訊流 (從左到右)
plt.annotate('', xy=(9.5, 0.1), xytext=(0.5, sample_seq[0]),
arrowprops=dict(arrowstyle="->", color='#e63946', lw=2.5, ls='--'))
# 反向資訊流 (從右到左)
plt.annotate('', xy=(10.5, 0.1), xytext=(19.5, sample_seq[-1]),
arrowprops=dict(arrowstyle="->", color='#457b9d', lw=2.5, ls='--'))
# 美化圖表
plt.title(f'Bi-directional LSTM Context Fusion Visualization\nTrue Target: {true_answer} | Bi-LSTM Prediction at Target Blank: {pred_answer}', fontsize=14, fontweight='bold')
plt.xlabel('Time Steps ($t$)', fontsize=12)
plt.ylabel('Signal Value', fontsize=12)
plt.xticks(time_steps)
plt.ylim(-0.5, 2.5)
# 文字說明
plt.text(2, 1.2, "Forward Layer:\nCaptures Past Clue", color='#e63946', fontweight='bold', fontsize=10)
plt.text(13, 1.2, "Backward Layer:\nCaptures Future Clue", color='#457b9d', fontweight='bold', fontsize=10)
plt.text(7.5, -0.4, "Information Fusion\nAt Time step 10", color='#2a9d8f', fontweight='bold', fontsize=10)
plt.grid(True, linestyle=':', alpha=0.5)
plt.legend(loc='upper center', bbox_to_anchor=(0.5, -0.15), ncol=3)
plt.tight_layout()
plt.show()