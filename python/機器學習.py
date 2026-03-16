import torch
import torch.nn as nn
from torch.optim import Adam
from torch.utils.data import Dataset, DataLoader
import torchvision.transforms.v2 as transforms
import torchvision.io as tv_io
import glob

# ==========================================
# 1. 全域常數與環境設定
# ==========================================
N_CLASSES = 6
IMG_WIDTH, IMG_HEIGHT = (224, 224)
DATA_LABELS = ["freshapples", "freshbanana", "freshoranges", "rottenapples", "rottenbanana", "rottenoranges"]
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# ==========================================
# 2. 模型架構定義 (VGG16 Base + Custom Head)
# ==========================================
from torchvision.models import vgg16, VGG16_Weights
weights = VGG16_Weights.IMAGENET1K_V1
vgg_model = vgg16(weights=weights)

# 凍結預訓練模型的特徵層，確保在初期訓練時底層權重不被破壞
vgg_model.requires_grad_(False) 

my_model = nn.Sequential(
    vgg_model.features,
    vgg_model.avgpool,
    nn.Flatten(),
    vgg_model.classifier[0:3],
    
    # 自定義的神經網路層，逐步降低維度並加入 Dropout 防過擬合
    nn.Linear(4096, 512),
    nn.ReLU(),
    nn.Dropout(p=0.5),
    
    nn.Linear(512, 256),
    nn.ReLU(),
    nn.Dropout(p=0.3),

    nn.Linear(256, 128),      
    nn.ReLU(),                
    nn.Dropout(p=0.3), 
    
    nn.Linear(128, N_CLASSES)
)
my_model = my_model.to(device)

loss_function = nn.CrossEntropyLoss()
# 使用極小的學習率 1e-4，避免優化步伐過大導致 Loss 震盪
optimizer = Adam(my_model.parameters(), lr=1e-4)

# ==========================================
# 3. 資料轉換 (Transforms) 嚴格分離
# ==========================================
# 訓練集專用：包含隨機翻轉、顏色抖動等資料增強技術
train_trans = transforms.Compose([
    transforms.ToImage(),
    transforms.RandomRotation(25),
    transforms.RandomResizedCrop((IMG_HEIGHT, IMG_WIDTH), scale=(.8, 1), ratio=(1, 1), antialias=True),
    transforms.RandomHorizontalFlip(),
    transforms.ColorJitter(brightness=.2, contrast=.2, saturation=.2, hue=.2),
    transforms.ToDtype(torch.float32, scale=True),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
])

# 驗證集專用：僅做縮放與標準化，不含隨機雜訊
valid_trans = weights.transforms()

# ==========================================
# 4. 資料集載入器 (延遲載入實作)
# ==========================================
class MyDataset(Dataset):
    def __init__(self, data_dir, transform=None):
        self.img_paths = [] # 僅儲存字串路徑，節省主機與顯示卡記憶體
        self.labels = []
        self.transform = transform
        
        for l_idx, label in enumerate(DATA_LABELS):
            data_paths = glob.glob(data_dir + label + '/*.png', recursive=True)
            for path in data_paths:
                self.img_paths.append(path)
                self.labels.append(l_idx)

    def __getitem__(self, idx):
        # 當 DataLoader 索要資料時，才進行 I/O 讀取與 Transform 計算
        img = tv_io.read_image(self.img_paths[idx], tv_io.ImageReadMode.RGB)
        label = torch.tensor(self.labels[idx], dtype=torch.long)
        
        if self.transform:
            img = self.transform(img)
            
        return img, label

    def __len__(self):
        return len(self.img_paths)

# ==========================================
# 5. 訓練與驗證輔助函式
# ==========================================
# 準確率計算邏輯不變
def get_batch_accuracy(output, y, N):
    pred = output.argmax(dim=1, keepdim=True)
    correct = pred.eq(y.view_as(pred)).sum().item()
    return correct / N

# 移除了 random_trans 參數，因為轉換已經在 DataLoader 內部完成
def train(model, train_loader, train_N, optimizer, loss_function):
    loss = 0
    accuracy = 0
    model.train() # 啟用 Dropout 隨機失活特性
    
    for x, y in train_loader:
        # 在這裡才將該批次的資料搬移至 GPU (RTX 4070)
        x, y = x.to(device), y.to(device)
        
        output = model(x)
        optimizer.zero_grad() # 清空過往梯度
        batch_loss = loss_function(output, y)
        batch_loss.backward() # 反向傳播計算梯度
        optimizer.step()      # 更新權重

        loss += batch_loss.item()
        accuracy += get_batch_accuracy(output, y, train_N)
        
    print('Train - Loss: {:.4f} Accuracy: {:.4f}'.format(loss, accuracy))

def validate(model, valid_loader, valid_N, loss_function):
    loss = 0
    accuracy = 0
    model.eval() # 關閉 Dropout，確保驗證結果穩定
    
    with torch.no_grad(): # 停止計算梯度，節省大量記憶體開銷
        for x, y in valid_loader:
            x, y = x.to(device), y.to(device)
            output = model(x)
            loss += loss_function(output, y).item()
            accuracy += get_batch_accuracy(output, y, valid_N)
            
    print('Valid - Loss: {:.4f} Accuracy: {:.4f}'.format(loss, accuracy))
    return accuracy

# ==========================================
# 6. 主執行迴圈
# ==========================================
n = 64
train_path = "data/fruits/train/"
train_data = MyDataset(train_path, transform=train_trans)
# DataLoader 會在背景開啟多執行緒呼叫 __getitem__
train_loader = DataLoader(train_data, batch_size=n, shuffle=True) 
train_N = len(train_loader.dataset)

valid_path = "data/fruits/valid/"
valid_data = MyDataset(valid_path, transform=valid_trans)
valid_loader = DataLoader(valid_data, batch_size=n, shuffle=False)
valid_N = len(valid_loader.dataset)

epochs = 50
target_accuracy = 0.92

for epoch in range(epochs):
    print('Epoch: {}'.format(epoch))
    # 呼叫同一份腳本上方的 train 與 validate
    train(my_model, train_loader, train_N, optimizer, loss_function)
    valid_accuracy = validate(my_model, valid_loader, valid_N, loss_function)
    
    if valid_accuracy is not None and valid_accuracy >= target_accuracy:
        print(f"驗證集準確率已達 {valid_accuracy*100:.2f}%，觸發提前停止。")
        torch.save(my_model.state_dict(), 'best_model_weights.pth')
        break