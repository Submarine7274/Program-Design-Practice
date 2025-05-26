import random

trials = 1000

a_win = 0
b_win = 0
both_win = 0  # 理論上應該是 0，因為只有一個獎品
neither_win = 0

for _ in range(trials):
    # 隨機決定哪一扇門有獎品（0~4）
    prize_door = random.randint(0, 4)
    
    # 玩家 A 隨機選一扇門
    a_choice = random.randint(0, 4)
    
    # 玩家 B 隨機選一扇不同於 A 的門
    remaining_doors = [i for i in range(5) if i != a_choice]
    b_choice = random.choice(remaining_doors)

    # 主持人開一扇門：不能是獎品，也不能是 A 或 B 的門
    unopened_doors = [i for i in range(5) if i != prize_door and i != a_choice and i != b_choice]
    host_opens = random.choice(unopened_doors)

    # 換門：從剩下的門（不是原選也不是主持人開的）中隨機挑一扇
    remaining_for_a = [i for i in range(5) if i != a_choice and i != host_opens and i != b_choice]
    a_new_choice = random.choice(remaining_for_a)

    remaining_for_b = [i for i in range(5) if i != b_choice and i != host_opens and i != a_new_choice]
    if remaining_for_b:  # 有時 B 沒得選（例如 A 換到了獎品），要檢查
        b_new_choice = random.choice(remaining_for_b)
    else:
        b_new_choice = b_choice  # 保留原選項

    # 統計誰中獎
    a_got = a_new_choice == prize_door
    b_got = b_new_choice == prize_door

    if a_got and b_got:
        both_win += 1
    elif a_got:
        a_win += 1
    elif b_got:
        b_win += 1
    else:
        neither_win += 1

# 輸出結果
print(f"模擬次數: {trials}")
print(f"A 中獎次數: {a_win}（{a_win / trials * 100:.2f}%）")
print(f"B 中獎次數: {b_win}（{b_win / trials * 100:.2f}%）")
print(f"兩人同時中獎（理論上應為 0）: {both_win}")
print(f"都沒中獎次數: {neither_win}（{neither_win / trials * 100:.2f}%）")
