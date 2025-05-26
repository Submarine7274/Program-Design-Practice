import random
trials = 1000

results = {
    "A不換_B不換": {"A": 0, "B": 0},
    "A換_B不換": {"A": 0, "B": 0},
    "A不換_B換": {"A": 0, "B": 0},
    "A換_B也換": {"A": 0, "B": 0},
}

for _ in range(trials):
    doors = [0, 1, 2, 3, 4]
    prize = random.choice(doors)

    # A、B最初選不同門
    A_choice = random.choice(doors)
    B_choice = random.choice([d for d in doors if d != A_choice])

    # 主持人開門：不能開A選、B選、獎品門
    host_candidates = [d for d in doors if d not in (A_choice, B_choice) and d != prize]
    host_open = random.choice(host_candidates)

    # 1. A不換_B不換
    A_final = A_choice
    B_final = B_choice
    if A_final == prize:
        results["A不換_B不換"]["A"] += 1
    if B_final == prize:
        results["A不換_B不換"]["B"] += 1

    # 2. A換_B不換 (A換門選項不含A自己原門、主持人開門、B原門)
    switch_pool_A = [d for d in doors if d != A_choice and d != host_open and d != B_choice]
    A_final = random.choice(switch_pool_A)
    B_final = B_choice
    if A_final == prize:
        results["A換_B不換"]["A"] += 1
    if B_final == prize:
        results["A換_B不換"]["B"] += 1

    # 3. A不換_B換 (B換門選項不含B自己原門、主持人開門、A原門)
    switch_pool_B = [d for d in doors if d != B_choice and d != host_open and d != A_choice]
    B_final = random.choice(switch_pool_B)
    A_final = A_choice
    if A_final == prize:
        results["A不換_B換"]["A"] += 1
    if B_final == prize:
        results["A不換_B換"]["B"] += 1

    # 4. A換_B也換 (雙人都換，選項不含自己原門、主持人開門，允許選對方原門)
    switch_pool_A = [d for d in doors if d != A_choice and d != host_open]
    switch_pool_B = [d for d in doors if d != B_choice and d != host_open]

    A_final = random.choice(switch_pool_A)
    # B換門時，排除主持人開門、B自己原門，但允許選A換後選的門（因為他們同時換門，順序隨機）
    # 這裡若要避免選同一扇門，可以改成先選A，再排除A選的門給B選
    switch_pool_B_exclude_Afinal = [d for d in switch_pool_B if d != A_final]
    if switch_pool_B_exclude_Afinal:
        B_final = random.choice(switch_pool_B_exclude_Afinal)
    else:
        B_final = random.choice(switch_pool_B)  # 只有一扇門的狀況

    if A_final == prize:
        results["A換_B也換"]["A"] += 1
    if B_final == prize:
        results["A換_B也換"]["B"] += 1
for scenario in results:
    print(f"{scenario}:")
    print(f"  A中獎次數: {results[scenario]['A']}, 中獎率: {results[scenario]['A']/trials*100:.2f}%")
    print(f"  B中獎次數: {results[scenario]['B']}, 中獎率: {results[scenario]['B']/trials*100:.2f}%")
