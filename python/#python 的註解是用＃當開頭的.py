#python 的註解是用＃當開頭的
# -*- coding: utf-8 -*-代表這些程式是用utf-8編碼的
#安裝完python後，只要在終端機輸入python3就可以進入python的互動式命令列
#他出現>>>後 就可以輸入指令了
#可以直接在直譯器上輸入指令 像是進行四則運算 例如>>> 3+4 
#他會輸出7
#其他運算符號如-減 *乘 /除(會返回浮點數) %(取餘數) //(取整除數) **(平方) 等等
#而 =符號用於賦值
#例如 a = 3 這樣就把3賦值給變數a
#變數可以用來儲存資料
#變數的命名規則是字母開頭 可以包含字母數字和底線 不能有空格
#變數的命名不能是python的保留字 例如if for while等
#可以用print()函數來輸出變數的值
#例如>>>width = 20
#>>>height = 5 * 9
#>>>width * height
#會輸出900
#如果要印出字串 可以使用print()函式 
#例如>>>print("Hello, World!")
#會輸出Hello, World!
#如果要印出變數的值 可以這樣做
#>>>print("The value of width is", width)
#會輸出The value of width is 20
#如果要印出多個變數的值 可以這樣做
#>>>print("The value of width is", width, "and the value of height is", height)
#會輸出The value of width is 20 and the value of height is 45
#如果要印出格式化的字串 可以使用f-string
#例如>>>name = "Alice"
#>>>age = 30
#>>>print(f"My name is {name} and I am {age} years old.")
#會輸出My name is Alice and I am 30 years old.
#如果要輸入多行字串 可以使用三個引號
#例如>>>text = """This is a multi-line string.
#It can span multiple lines."""
#>>>print(text)
#會輸出
#This is a multi-line string.
#It can span multiple lines.
#如果要輸入單行字串 可以使用單引號或雙引號
#例如>>>text = 'This is a single-line string.'
#>>>print(text)
#會輸出This is a single-line string.
#如果要輸入帶有引號的字串 可以使用轉義字符\
#例如>>>text = "He said, \"Hello, World!\""
#>>>print(text)
#會輸出He said, "Hello, World!"
#如果要輸入帶有單引號的字串 可以使用雙引號
#例如>>>text = 'It\'s a sunny day.'
#>>>print(text)
#會輸出It's a sunny day.
#如果要輸入帶有雙引號的字串 可以使用單引號
#例如>>>text = "She said, 'Hello!'"
#>>>print(text)
#會輸出She said, 'Hello!'
#如果要輸入帶有反斜線的字串 可以使用雙反斜線
#例如>>>text = "This is a backslash: \\"
#>>>print(text)
#會輸出This is a backslash: \
#如果要輸入帶有換行符的字串 可以使用\n
#例如>>>text = "This is a line.\nThis is another line."
#>>>print(text)
#會輸出         
#This is a line.
#This is another line.
#如果要輸入帶有制表符的字串 可以使用\t 
#例如>>>text = "This is a tab:\tThis is after the tab."
#>>>print(text)
#會輸出This is a tab:    This is after the tab.
#如果要輸入帶有Unicode字符的字串 可以使用\u
#例如>>>text = "This is a Unicode character: \u03A9"
#>>>print(text)
#會輸出This is a Unicode character: Ω
#如果要輸入帶有十六進制字符的字串 可以使用\x
#例如>>>text = "This is a hex character: \x41"
#>>>print(text)
#會輸出This is a hex character: A
#如果要輸入帶有八進制字符的字串 可以使用\o
#例如>>>text = "This is an octal character: \o101"
#>>>print(text)
#會輸出This is an octal character: A
#如果要輸入帶有ASCII字符的字串 可以使用\a
#例如>>>text = "This is an ASCII character: \a"
#>>>print(text)
#會輸出This is an ASCII character: (發出ㄅㄧ 聲)
