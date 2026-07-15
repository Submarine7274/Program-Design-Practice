import torch
import torch.nn as nn
import torch.optim as optim
import math
# 1. 建立微型英中字典
english_vocab = {"<pad>": 0, "<bos>": 1, "<eos>": 2, "i": 3, "love": 4, "ai.": 5}
chinese_vocab = {"<pad>": 0, "<bos>": 1, "<eos>": 2, "我": 3, "愛": 4, "人工": 5, "智能": 6}
# 反向字典（ID 轉文字），推論時使用
inv_chinese_vocab = {v: k for k, v in chinese_vocab.items()}
# 2. 定義位置編碼 (Positional Encoding)
class PositionalEncoding(nn.Module):
    def __init__(self, d_model, max_len=10):
        super(PositionalEncoding, self).__init__()
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-math.log(10000.0) / d_model))
        pe[:, 0::2] = torch.sin(position * div_term)
        pe[:, 1::2] = torch.cos(position * div_term)
        self.register_buffer('pe', pe.unsqueeze(0))
    def forward(self, x):
        return x + self.pe[:, :x.size(1)]
    # 3. 定義完整的 Transformer Seq2Seq 模型
class TransformerTranslator(nn.Module):
    def __init__(self, src_vocab_size, tgt_vocab_size, d_model=16, nhead=2, num_layers=1):
        super(TransformerTranslator, self).__init__()
        self.d_model = d_model
        # 嵌入層
        self.src_embedding = nn.Embedding(src_vocab_size, d_model)
        self.tgt_embedding = nn.Embedding(tgt_vocab_size, d_model)
        self.pos_encoder = PositionalEncoding(d_model)
        # PyTorch 核心 Transformer 模組
        self.transformer = nn.Transformer(
        d_model=d_model, nhead=nhead,
        num_encoder_layers=num_layers, num_decoder_layers=num_layers,
        dim_feedforward=32, batch_first=True
        )
        # 輸出層
        self.fc_out = nn.Linear(d_model, tgt_vocab_size)
    def generate_square_subsequent_mask(self, sz):
        mask = (torch.triu(torch.ones(sz, sz)) == 1).transpose(0, 1)
        mask = mask.float().masked_fill(mask == 0, float('-inf')).masked_fill(mask == 1, float(0.0))
        return mask
    def forward(self, src, tgt):
        src_emb = self.pos_encoder(self.src_embedding(src) * math.sqrt(self.d_model))
        tgt_emb = self.pos_encoder(self.tgt_embedding(tgt) * math.sqrt(self.d_model))
        tgt_mask = self.generate_square_subsequent_mask(tgt.size(1)).to(src.device)
        out = self.transformer(src_emb, tgt_emb, tgt_mask=tgt_mask)
        return self.fc_out(out)
# 4. 準備訓練資料 ("I love ai." -> "我 愛 人工 智能")
src_tokens = [english_vocab["i"], english_vocab["love"], english_vocab["ai."]]
tgt_tokens = [chinese_vocab["<bos>"], chinese_vocab["我"], chinese_vocab["愛"], chinese_vocab["人工"], chinese_vocab["智能"]]
tgt_output_tokens = [chinese_vocab["我"], chinese_vocab["愛"], chinese_vocab["人工"], chinese_vocab["智能"], chinese_vocab["<eos>"]]
# 轉為 Tensor 並加上 Batch 維度
src = torch.tensor([src_tokens], dtype=torch.long)
tgt_in = torch.tensor([tgt_tokens], dtype=torch.long)
tgt_out = torch.tensor([tgt_output_tokens], dtype=torch.long)
# 5. 初始化模型與極速優化訓練 (Overfitting 訓練法)
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = TransformerTranslator(len(english_vocab), len(chinese_vocab)).to(device)
criterion = nn.CrossEntropyLoss(ignore_index=0)
optimizer = optim.Adam(model.parameters(), lr=0.01)
src, tgt_in, tgt_out = src.to(device), tgt_in.to(device), tgt_out.to(device)
model.train()
for epoch in range(120): # 訓練 120 次讓微型模型牢牢記住這句話
    optimizer.zero_grad()
output = model(src, tgt_in)
loss = criterion(output.view(-1, len(chinese_vocab)), tgt_out.view(-1))
loss.backward()
optimizer.step()
# 6. 自迴歸模型推論 (Autoregressive Inference)
model.eval()
print("【開始翻譯】")
print("輸入英文句子: I love ai.")
# 初始化解碼器的第一個輸入只有 <bos>
translated_ids = [chinese_vocab["<bos>"]]
with torch.no_grad():
    for _ in range(5): # 最多預測 5 個字
        tgt_tensor = torch.tensor([translated_ids], dtype=torch.long).to(device)
        predictions = model(src, tgt_tensor)
        # 取得最後一個時間步預測機率最大的單字 ID
        next_word_id = predictions[0, -1, :].argmax().item()
        if next_word_id == chinese_vocab["<eos>"]:
            break
        translated_ids.append(next_word_id)
        # 將 ID 陣列轉回中文文字
        final_translation = [inv_chinese_vocab[idx] for idx in translated_ids[1:]] # 略過 <bos>
print("模型中文翻譯:", "".join(final_translation))