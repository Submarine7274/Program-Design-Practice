import random
import itertools

def calculate_ab(target: str, guess: str):
    # 為什麼這樣寫：因為允許前導零，兩者皆視為字串傳入。
    a = 0
    b = 0
    for i in range(4):
        if guess[i] == target[i]:
            a += 1
        # 為什麼這樣寫：Python 的 in 關鍵字可以直接檢查字元是否存在於另一個字串中
        elif guess[i] in target: 
            b += 1
    return a, b

def main():
    # 1. 初始化所有可能的四位數組合
    # 為什麼這樣寫：利用 itertools.permutations 產生所有 0-9 取 4 個不重複的排列。
    # p 會是類似 ('0', '1', '2', '3') 的元組 (Tuple)。
    # "".join(p) 會將元組內的字元合併成字串 "0123"。
    # 這行「串列推導式」直接取代了 C++ 版本中冗長的迴圈與 hasDuplicate 檢查。
    possible_numbers = ["".join(p) for p in itertools.permutations("0123456789", 4)]

    # 2. 隨機挑選目標數字
    # 為什麼這樣寫：random.choice 可以直接從串列中隨機抽取一個元素，省去計算索引的步驟。
    target = random.choice(possible_numbers)
    
    print("目標數字已生成，請開始猜測（0123~9876，不可重複數字，可包含前導零）：\n")

    while True:
        # 在 Python 中，input() 預設讀取進來的型別就是字串 (str)
        guess = input("請輸入四位數：")

        # 3. 輸入防呆驗證
        if len(guess) != 4:
            print("錯誤：請輸入剛好四個數字。\n")
            continue
        
        # 為什麼這樣寫：isdigit() 是字串的內建方法，檢查是否全為 0-9 的數字，取代 C++ 的 isdigit(c) 迴圈
        if not guess.isdigit():
            print("錯誤：請只輸入數字（0-9）。\n")
            continue
        
        # 為什麼這樣寫：set(guess) 會把字串拆成集合並去除重複字元。
        # 如果原本長度 4 的字串有重複字元，轉為 set 後長度一定小於 4。
        if len(set(guess)) != 4:
            print("錯誤：數字不可重複。\n")
            continue

        # 4. 計算 A 與 B
        a, b = calculate_ab(target, guess)

        # 5. 篩選剩餘的可能組合
        # 為什麼這樣寫：基於數學邏輯，只要新的候選名單符合當前猜測的 A/B 結果，就等同於符合所有歷史紀錄。
        # 因此直接用推導式覆蓋 possible_numbers 變數，不需要像 C++ 一樣維護 history 結構體。
        possible_numbers = [num for num in possible_numbers if calculate_ab(num, guess) == (a, b)]
        
        valid_combos = len(possible_numbers)

        # 6. 計算機率與顯示結果
        next_guess_probability = (100.0 / valid_combos) if valid_combos > 0 else 0.0

        print(f"你猜的數字是：{guess}")
        print(f"下一次猜中機率為：{next_guess_probability:.2f}%")
        print(f"剩下的可能性有 {valid_combos} 種")
        print(f"結果：{a}A{b}B\n")

        if a == 4:
            print(f"恭喜你猜對了！答案是：{target}")
            break

        if valid_combos <= 0:
            print("發生異常：所有可能性都排除了，請檢查邏輯。")
            break

if __name__ == "__main__":
    main()