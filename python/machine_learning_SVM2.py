import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm, datasets
from sklearn.datasets import make_circles
# 1. 生成非線性資料集（環形資料）
# factor 控制內外圈距離，noise 控制點的散布程度
X, y = make_circles(n_samples=1000, factor=0.3, noise=0.2, random_state=42)
# 2. 定義要比較的核函數
kernels = ['linear', 'poly', 'rbf']
models = [
svm.SVC(kernel='linear'),
svm.SVC(kernel='poly', degree=2), # 多項式核，設定為二次方
svm.SVC(kernel='rbf', gamma=0.7) # RBF 核
]
# 3. 繪圖準備
fig, axes = plt.subplots(1, 3, figsize=(15, 5))
titles = ['Linear Kernel', 'Polynomial Kernel (degree 2)', 'RBF Kernel']
# 建立網格以繪製決策邊界
h = .02
x_min, x_max = X[:, 0].min() - 0.5, X[:, 0].max() + 0.5
y_min, y_max = X[:, 1].min() - 0.5, X[:, 1].max() + 0.5
xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
# 4. 訓練並視覺化
for clf, title, ax in zip(models, titles, axes):
    clf.fit(X, y)
    # 預測網格點的類別
    Z = clf.predict(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
    # 繪製等高線（決策區域）
    ax.contourf(xx, yy, Z, cmap=plt.cm.coolwarm, alpha=0.8)
    # 繪製原始資料點
    ax.scatter(X[:, 0], X[:, 1], c=y, cmap=plt.cm.coolwarm, edgecolors='k')
    ax.set_title(title)
    ax.set_xticks(())
    ax.set_yticks(())
plt.tight_layout()
plt.show()