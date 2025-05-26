import random

trials = 1000
win_if_switch = 0
win_if_stay = 0

for _ in range(trials):
    doors = [0, 1, 2]
    car = random.choice(doors)       # 汽車位置
    player_choice = random.choice(doors)  # 玩家初始選擇

    # 主持人開一扇空的門（不是玩家選的門、也不是汽車所在的那扇門）
    remaining_doors = [d for d in doors if d != player_choice and d != car]
    host_open = random.choice(remaining_doors)

    # 換門的選擇是剩下那一扇門（不是原選、不是主持人開的）
    switch_choice = [d for d in doors if d != player_choice and d != host_open][0]

    if switch_choice == car:
        win_if_switch += 1
    if player_choice == car:
        win_if_stay += 1

print(f"總模擬次數: {trials}")
print(f"不換門中獎次數: {win_if_stay}，機率: {win_if_stay / trials * 100:.2f}%")
print(f"換門中獎次數: {win_if_switch}，機率: {win_if_switch / trials * 100:.2f}%")