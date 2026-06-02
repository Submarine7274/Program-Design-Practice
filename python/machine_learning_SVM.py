import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import classification_report, confusion_matrix
# 1. 載入資料集 (使用鳶尾花資料集)
iris = datasets.load_iris()
# 為了方便視覺化，我們只取前兩個特徵 (花萼長度與寬度)
X = iris.data[:, :2]
y = iris.target
# 2. 切分訓練集與測試集 (80% 訓練, 20% 測試)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
# 3. 特徵標準化 (SVM 對數值範圍很敏感，這是必經步驟)
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
# 4. 建立 SVM 模型
# kernel='rbf' 是最常用的非線性核函數
# C 是懲罰參數，gamma 決定了核函數的影響範圍
model = SVC(kernel='rbf', C=1.0, gamma='auto')
# 5. 訓練模型
model.fit(X_train, y_train)
# 6. 進行預測
y_pred = model.predict(X_test)
# 7. 輸出評估結果
print("--- 混淆矩陣 (Confusion Matrix) ---")
print(confusion_matrix(y_test, y_pred))
print("\n--- 分類報告 (Classification Report) ---")
print(classification_report(y_test, y_pred))
# 8. 視覺化分類邊界
def plot_contours(ax, clf, xx, yy, **params):
    Z = clf.predict(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
    out = ax.contourf(xx, yy, Z, **params)
    return out
fig, ax = plt.subplots(figsize=(8, 6))
X0, X1 = X_train[:, 0], X_train[:, 1]
xx, yy = np.meshgrid(np.arange(X0.min()-1, X0.max()+1, 0.02),
            np.arange(X1.min()-1, X1.max()+1, 0.02))
plot_contours(ax, model, xx, yy, cmap=plt.cm.coolwarm, alpha=0.8)
ax.scatter(X0, X1, c=y_train, cmap=plt.cm.coolwarm, s=20, edgecolors='k')
ax.set_xlabel('Sepal length (standardized)')
ax.set_ylabel('Sepal width (standardized)')
ax.set_title('SVM Classification with RBF Kernel')
plt.show()