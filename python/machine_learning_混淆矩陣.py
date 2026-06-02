import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_classification
from sklearn.linear_model import LogisticRegression
# 1. 產生模擬數據 (模擬 1000 筆交易，其中詐欺交易佔少數)
X, y = make_classification(n_samples=1000, n_features=2, n_redundant=0,
n_clusters_per_class=1, weights=[0.9], flip_y=0, random_state=42)
# 2. 切分訓練集與測試集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)
# 3. 訓練邏輯迴歸模型
model = LogisticRegression()
model.fit(X_train, y_train)
# 4. 進行預測
y_pred = model.predict(X_test)
# 5. 計算混淆矩陣
cm = confusion_matrix(y_test, y_pred)
# 6. 視覺化混淆矩陣
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues',
xticklabels=['Normal', 'Fraud'],
yticklabels=['Normal', 'Fraud'])
plt.xlabel('Predicted Label')
plt.ylabel('True Label')
plt.title('Confusion Matrix - Credit Card Fraud Detection')
plt.show()
# 7. 印出詳細評估報告 (包含 Precision, Recall, F1-score)
print("\n--- Classification Report ---")
print(classification_report(y_test, y_pred, target_names=['Normal', 'Fraud']))