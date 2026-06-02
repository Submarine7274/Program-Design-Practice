import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt
# 1. 準備數據：y = 2x
x_train = torch.linspace(-10, 10, 100).view(-1, 1)
y_true = 2 * x_train
# 2. 定義三種不同的模型設計
class RegressionModel(nn.Module):
    def __init__(self, activation_type='none'):
        super().__init__()
        self.fc = nn.Linear(1, 1)
        self.activation_type = activation_type
    def forward(self, x):
        x = self.fc(x)
        if self.activation_type == 'relu':
            return torch.relu(x) # 誤用：限制了負值輸出
        elif self.activation_type == 'sigmoid':
            return torch.sigmoid(x) # 誤用：限制在 0~1 之間
        return x # 正確：線性輸出層
    # 3. 訓練函數
def train(model):
    optimizer = optim.Adam(model.parameters(), lr=0.1)
    criterion = nn.MSELoss()
    for _ in range(500):
        optimizer.zero_grad()
        loss = criterion(model(x_train), y_true)
        loss.backward()
        optimizer.step()
    return model
model_correct = train(RegressionModel(activation_type='none'))
model_relu = train(RegressionModel(activation_type='relu'))
model_sigmoid = train(RegressionModel(activation_type='sigmoid'))
plt.figure(figsize=(10, 6))
plt.plot(x_train.numpy(), y_true.numpy(), 'k--', label='True Function (y=2x)', alpha=0.5)
plt.plot(x_train.numpy(), model_correct(x_train).detach().numpy(), 'g-', label='Correct (Linear Output)')
plt.plot(x_train.numpy(), model_relu(x_train).detach().numpy(), 'r-', label='Wrong (ReLU Output)')
plt.plot(x_train.numpy(), model_sigmoid(x_train).detach().numpy(), 'b-', label='Wrong (Sigmoid Output)')
plt.title("Impact of Misusing Activation Functions in Regression")
plt.xlabel("Input x")
plt.ylabel("Output y")
plt.legend()
plt.grid(True)
plt.show()