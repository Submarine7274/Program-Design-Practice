import torch
import torch.nn.functional as F
import matplotlib.pyplot as plt
# 1. 建立輸入數據 (-5 到 5 之間的連續數值)
x = torch.linspace(-5, 5, 200)
# 2. 計算各個激活函數的輸出
y_sigmoid = torch.sigmoid(x)
y_tanh = torch.tanh(x)
y_relu = torch.relu(x)
# Softmax 通常作用於一組向量，這裡為了視覺化，我們對整個數列進行轉換
y_softmax = F.softmax(x, dim=0)
# 3. 繪圖展示差異
plt.figure(figsize=(12, 8))
# 繪製 Sigmoid
plt.subplot(2, 2, 1)
plt.plot(x.numpy(), y_sigmoid.numpy(), 'b', label='Sigmoid')
plt.title('Sigmoid (0 to 1)')
plt.grid(True)
plt.legend()
# 繪製 Tanh
plt.subplot(2, 2, 2)
plt.plot(x.numpy(), y_tanh.numpy(), 'g', label='Tanh')
plt.title('Tanh (-1 to 1)')
plt.grid(True)
plt.legend()
# 繪製 ReLU
plt.subplot(2, 2, 3)
plt.plot(x.numpy(), y_relu.numpy(), 'r', label='ReLU')
plt.title('ReLU (0 to x)')
plt.grid(True)
plt.legend()
# 繪製 Softmax
plt.subplot(2, 2, 4)
plt.plot(x.numpy(), y_softmax.numpy(), 'm', label='Softmax')
plt.title('Softmax (Probability Distribution)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()