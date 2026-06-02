from sklearn import svm
import matplotlib.pyplot as plt
import numpy as np
# 建立一些有噪訊的資料
X = np.array([[1, 2], [2, 3], [3, 3], [2, 1], [3, 2], [4, 2], [1, 5], [5, 1]])
y = [0, 0, 0, 0, 1, 1, 1, 1] # 故意讓分類不是那麼完美
# 建立兩個模型對比
# C=100 接近 Hard Margin (嘗試嚴格分類)
# C=0.1 則是 Soft Margin (容許更多錯誤以換取寬邊界)
models = [svm.SVC(kernel='rbf', C=100), svm.SVC(kernel='rbf', C=0.1)]#kernel可以改成rbf linear 
titles = ['C=100 (Harder Margin)', 'C=0.1 (Softer Margin)']
for i, clf in enumerate(models):
	clf.fit(X, y)
	plt.subplot(1, 2, i+1)
	plt.scatter(X[:, 0], X[:, 1], c=y, cmap='coolwarm')
	# 繪製邊界
	ax = plt.gca()
	xlim = ax.get_xlim()
	ylim = ax.get_ylim()
	xx, yy = np.meshgrid(np.linspace(xlim[0], xlim[1], 30), np.linspace(ylim[0], ylim[1], 30))
	Z = clf.decision_function(np.c_[xx.ravel(), yy.ravel()]).reshape(xx.shape)
	ax.contour(xx, yy, Z, colors='k', levels=[-1, 0, 1], alpha=0.5, linestyles=['--', '-', '--'])
plt.title(titles[i])
plt.show()