import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix, classification_report
# 1. 手動建立「極端」的測試數據 (1 = 生病, 0 = 健康)
# 假設有 1000 筆資料，其中只有 50 筆是真正的病人
y_true = np.array([0] * 2000 + [1] * 50)
# 2. 模擬模型的「預測機率」
# 我們故意讓模型對病人的把握度不高（機率分布在 0.05 到 0.6 之間）
np.random.seed(42)
probs = np.zeros(2050) #改array這邊要改成總和
probs[:2000] = np.random.uniform(0, 0.3, 2000) # 健康的人，機率低
probs[2000:] = np.random.uniform(0.05, 0.6, 50) # 病人，但機率分佈很廣
# 3. 定義比較函數
def evaluate_threshold(threshold):
	y_pred = (probs >= threshold).astype(int)
	cm = confusion_matrix(y_true, y_pred)
	# 提取指標
	report = classification_report(y_true, y_pred, output_dict=True, zero_division=0)
	recall = report['1']['recall']
	precision = report['1']['precision']
	return y_pred, cm, recall, precision
# 4. 繪圖與比較
thresholds = [0.5, 0.1]
plt.figure(figsize=(12, 5))
for i, t in enumerate(thresholds):
	y_pred, cm, rec, pre = evaluate_threshold(t)
	plt.subplot(1, 2, i+1)
	sns.heatmap(cm, annot=True, fmt='d', cmap='RdPu',
	xticklabels=['Healthy', 'Sick'],
	yticklabels=['Healthy', 'Sick'])
	plt.title(f"Threshold: {t}\nRecall (Sick): {rec:.2f} | Precision: {pre:.2f}")
	plt.xlabel('Predicted')
	plt.ylabel('Actual')
plt.tight_layout()
plt.show()