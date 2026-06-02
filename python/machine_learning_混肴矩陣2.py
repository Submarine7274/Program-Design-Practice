import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_classification
from sklearn.linear_model import LogisticRegression
# 1. 產生高度不平衡的模擬數據 (90% 正常, 10% 詐欺)
X, y = make_classification(n_samples=10000, n_features=2, n_redundant=0,
n_clusters_per_class=1, weights=[0.9], flip_y=0, random_state=42)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3,
random_state=42)
# 2. 訓練模型
model = LogisticRegression()
model.fit(X_train, y_train)
# 3. 獲取預測機率 (而不是直接預測類別)
# predict_proba 會輸出 [機率_0, 機率_1]，我們取索引 1 (即詐欺的機率)
y_probs = model.predict_proba(X_test)[:, 1]
# 4. 定義兩個不同的門檻
thresholds = [0.5, 0.2] # 0.5 是預設, 0.2 是為了提升 Recall 的激進門檻
plt.figure(figsize=(14, 5))
for i, threshold in enumerate(thresholds):
    # 根據門檻進行分類
    y_pred = (y_probs >= threshold).astype(int)
    # 計算混淆矩陣
    cm = confusion_matrix(y_test, y_pred)
    # 繪製子圖
    plt.subplot(1, 2, i+1)
    sns.heatmap(cm, annot=True, fmt='d', cmap='Oranges',
    xticklabels=['Normal', 'Fraud'],
    yticklabels=['Normal', 'Fraud'])
    plt.title(f'Threshold = {threshold}')
    plt.xlabel('Predicted')
    plt.ylabel('Actual')
    print(f"\n--- 門檻為 {threshold} 的報告---")
    print(classification_report(y_test, y_pred, target_names=['Normal', 'Fraud']))
plt.tight_layout()
plt.show()