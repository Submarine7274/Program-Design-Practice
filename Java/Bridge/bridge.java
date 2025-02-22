/*功能說明：
可以印出三種圖形：實心三角形、空心三角形、實心正方形、空心正方形
有兩種筆刷：字母跟數字
字母：A~Z輪流，每一行使用同一個字母
數字：0~9輪流，每一行使用同一個數字
Interface Brush 說明：
有一個int i = 0
有一個abstract void print(int i) 
Class Alphabate 說明：
Alphabate需要實作Brush
Alphabate需要實作print(int i)
Class Number 說明：
Number需要實作Brush
Number需要實作print(int i)
Class Shape 說明：
Shape有一個 int size代表尺寸
Shape有一個 Brush brush 代表筆刷
Shape有一個建構子 Shape(String br)
Shape有一個 abstract void draw(int size)畫圖
Class Triangle 說明：
Triangle繼承 Shape
Triangle有一個建構子 Triangle(String br)
Triangle需要實作draw(int size)
Class HollowTriangle 說明：
HollowTriangle繼承 Shape
HollowTriangle有一個建構子 HollowTriangle(String br)
HollowTriangle需要實作draw(int size)
Class Square 說明：
Square繼承 Shape
Square有一個建構子 Square(String br)
Square需要實作draw(int size)
Class HollowSquare 說明：
HollowSquare繼承 Shape
HollowSquare有一個建構子 HollowSquare(String br)
HollowSquare需要實作draw(int size)
Class Main 說明：
Main需要建立Shape物件
Main執行流程：
輸入一個字串代表使用的筆刷
ab: 字母
no: 數字
輸入一個字串選擇要畫的形狀
tr: 實心三角形
htr: 空心三角形
sq: 實心正方形
hsq: 空心正方形
輸入一個int代表尺寸
執行Shape.draw(size)
輸入：
ab
hrt
8

輸出：
A
B B
C C
D D
E E
F F
G G
HHHHHHHHHHHHHHH
輸入：
no
sq
6

輸出：
111111
222222
333333
444444
555555
666666*/