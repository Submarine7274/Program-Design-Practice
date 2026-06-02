import torch
import torch.nn as nn
import numpy as np
import matplotlib.pyplot as plt
# 設定隨機種子以確保結果可重現
torch.manual_seed(123)
np.random.seed(123)
# 1. 超參數設定
input_size = 1 # 每個時間步輸入 1 個數字
hidden_size = 8 # GRU 隱藏層的神經元數量
output_size = 3 # 輸出分類：0, 1, 2 (預測最開頭的秘密數字)
sequence_length = 20
num_epochs = 400
learning_rate = 0.02
# 2. 建立資料集 (Delayed Copy Task)
def generate_gru_data(num_samples, seq_len):
    # 初始化資料：全部填 0
    X = np.zeros((num_samples, seq_len, 1), dtype=np.float32)
    # 隨機決定開頭的秘密數字是 1 還是 2
    secret_numbers = np.random.choice([1, 2], size=num_samples)
    X[:, 0, 0] = secret_numbers
    # 標籤(Label)就是最開頭的那個秘密數字
    y = secret_numbers.astype(np.int64)
    return torch.tensor(X), torch.tensor(y)
X_train, y_train = generate_gru_data(100, sequence_length)
X_test, y_test = generate_gru_data(10, sequence_length)
# 3. 定義 GRU 模型
class SimpleGRU(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super(SimpleGRU, self).__init__()
        # batch_first=True 代表輸入維度為 (batch, seq, feature)
        self.gru = nn.GRU(input_size, hidden_size, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)
    def forward(self, x):
        # out 的維度: (batch, seq_len, hidden_size)
        # h_n 的維度: (num_layers, batch, hidden_size)
        out, h_n = self.gru(x)
        # 取出最後一個時間步的隱藏狀態送給全連接層
        out = self.fc(out[:, -1, :])
        return out
model = SimpleGRU(input_size, hidden_size, output_size)
criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)
# 4. 模型訓練
loss_history = []
print("開始訓練 GRU 模型...")
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
    test_outputs = model(X_test)
    predictions = torch.argmax(test_outputs, dim=1)
    accuracy = (predictions == y_test).float().mean()
    print(f"\n測試集準確率: {accuracy.item() * 100:.1f}%")
# 選擇第 1 個測試樣本來可視化
sample_idx = 2
sample_seq = X_test[sample_idx].numpy().flatten()
true_secret = y_test[sample_idx].item()
pred_secret = predictions[sample_idx].item()
time_steps = np.arange(sequence_length)
plt.figure(figsize=(12, 5))
# 繪製輸入訊號走勢(使用階梯圖更符合離散時間步)
plt.step(time_steps, sample_seq, where='mid', color='#2a9d8f', linewidth=2.5, label='GRU Input Sequence ($x_t$)')
plt.scatter([0], [sample_seq[0]], color='#e76f51', s=150, zorder=5, label=f'Secret Number ({true_secret})')
# 標註與美化
plt.title(f'GRU Long-Term Memory Visualization\nTrue Class: {true_secret} | GRU Prediction: {pred_secret}', fontsize=14, fontweight='bold')
plt.xlabel('Time Steps ($t$)', fontsize=12)
plt.ylabel('Signal Value', fontsize=12)
plt.xticks(time_steps)
plt.ylim(-0.5, 2.5)
# 加入記憶機制註解
plt.annotate('1. Secret info memorized by GRU', xy=(0, sample_seq[0]), xytext=(1.5, 2.2),
arrowprops=dict(facecolor='black', shrink=0.08, width=1, headwidth=6))
plt.annotate('2. Update Gate (z_t) protects this memory\nthroughout the 18 steps of zeros', xy=(10, 0), xytext=(4, 0.8),
arrowprops=dict(facecolor='gray', shrink=0.08, width=1, headwidth=6, alpha=0.5))
plt.annotate(f'3. Final step: GRU recalls successfully!\nPrediction = {pred_secret}', xy=(19, 0), xytext=(12, 1.8),
arrowprops=dict(facecolor='green', shrink=0.08, width=1, headwidth=6))
plt.grid(True, linestyle=':', alpha=0.6)
plt.legend(loc='upper right')
plt.tight_layout()
plt.show()