print("輸入一整串分數，以空格分隔：")
scores_input = input()
scores_str_list = scores_input.split()
scores = [float(score) for score in scores_str_list]
for score in scores:
    if score < 60 :
        print("不及格")
    elif score > 60 :
        print("及格")
    elif score ==60 :
        print("壓線")