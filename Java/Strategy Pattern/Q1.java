/*功能說明：
計算機可執行的運算為兩個整數的加減乘除
Interface IStrategy 說明：
有一個abstract int calculate(int a, int b)
Class Add 說明：
Add需要實作IStrategy
Add實作calculate(int a, int b)
Class Minus 說明：
Minus需要實作IStrategy
Minus實作calculate(int a, int b)
Class Multiply 說明：
Multiply需要實作IStrategy
Multiply實作calculate(int a, int b)
Class Divide 說明：
Divide需要實作IStrategy
Divide實作calculate(int a, int b)
Class Calculator 說明：
Calculator有一個 private IStrategy strategy
Calculator有一個 public int execute(int a , int b)
Class Main 說明：
Main需要建立Calculator物件
Main執行流程：
輸入算式，數字與運算元以空白隔開
以整數格式輸出計算結果
輸入：
256 + 743
輸出：
999
*/