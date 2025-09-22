#include <stdio.h>

int main(void) {
    float number = 0.0f, result = 0.0f;    //宣告變數 結果與輸入數字
    char operator;                     //宣告變數 運算子
    printf("Enter an expression (example: 1+2.5*3): ");    //提示輸入
    scanf("%f", &result);               //讀取第一個數字
    while ((operator = getchar()) != '\n'){ //讀取運算子直到遇到換行符號
        switch (operator) { //根據運算子進行相應的計算
            case '+':   //加法
                scanf("%f", &number);
                result += number;
                break;
            case '-':   //減法
                scanf("%f", &number);
                result -= number;
                break;
            case '*':   //乘法
                scanf("%f", &number);
                result *= number;
                break;
            case '/':   //除法
                scanf("%f", &number);
                result /= number;
                break;
            default:
                printf("Invalid operator: %c. Stopping calculations.\n", operator); //處理無效運算子
                break;
        }
    }
    printf("Value of expression: %.1f\n", result);
    return 0;
}
