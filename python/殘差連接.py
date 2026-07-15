import torch
import torch.nn as nn
class ResidualBlock(nn.Module):
    def __init__(self, dim):
        super(ResidualBlock, self).__init__()
        # 模擬一個簡單的網絡層 F(x)，例如 Transformer 中的 Feed-Forward 層
        # 為了展示效果，我們刻意將權重初始化得非常小(模擬深層網路中權重衰減、訊號變弱的情況)
        self.linear1 = nn.Linear(dim, dim)
        self.linear2 = nn.Linear(dim, dim)
        with torch.no_grad():
            self.linear1.weight.fill_(0.01)
            self.linear2.weight.fill_(0.01)
    def forward(self, x, use_residual=True):
    # 殘差路徑加工：F(x)
        fx = torch.relu(self.linear1(x))
        fx = self.linear2(fx)
        if use_residual:
        # 殘差連接：F(x) + x
            return fx + x
        else:
# 傳統連接：僅輸出 F(x)
            return fx
# --- 測試與梯度對比範例 ---
dim = 4
# 模擬前一層傳過來的輸入 x，並開啟梯度追蹤
x_with_res = torch.tensor([[2.0, -1.0, 3.0, 0.5]], requires_grad=True)
x_no_res = torch.tensor([[2.0, -1.0, 3.0, 0.5]], requires_grad=True)# 實例化相同的網路層
block_with_res = ResidualBlock(dim)
block_no_res = ResidualBlock(dim)
# --- 情況 A：使用殘差連接 ---
output_res = block_with_res(x_with_res, use_residual=True)
# 模擬損失函數(Loss)，對輸出求總和並進行反向傳播
loss_res = output_res.sum()
loss_res.backward()
# --- 情況 B：不使用殘差連接(傳統網路) ---
output_no_res = block_no_res(x_no_res, use_residual=False)
loss_no_res = output_no_res.sum()
loss_no_res.backward()
# 打印結果
print("=== 前向傳播 (Forward) 輸出結果對比 ===")
print("原始輸入 x :", [[2.0, -1.0, 3.0, 0.5]])
print("A. 有殘差連接的輸出:", output_res.detach().numpy())
print("B. 無殘差連接的輸出:", output_no_res.detach().numpy())
print("\n=== 反向傳播 (Backward) 傳回底層的梯度對比 ===")
print("A. 有殘差連接時，x 的梯度 (dx):",
x_with_res.grad.numpy())
print("B. 無殘差連接時，x 的梯度 (dx):", x_no_res.grad.numpy())