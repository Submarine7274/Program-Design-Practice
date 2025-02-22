#include <stdio.h>

int main(void) {
    float num = 0.0f, result = 0.0f;
    char operator;

    printf("Enter an expression (example: 1+2.5*3): ");
    // 讀取初始數字
    scanf("%f", &result);

    // 讀取運算符和數字，直到無法再讀取
    while (scanf(" %c%f", &operator, &num) == 2) {
        switch (operator) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                if (num != 0) {  // 防止除以零
                    result /= num;
                } else {
                    printf("Error: Division by zero.\n");
                    return 1;  // 返回錯誤代碼
                }
                break;
            default:
                printf("Invalid operator: %c. Stopping calculations.\n", operator);
                return 1;  // 返回錯誤代碼
        }
    }

    // 輸出結果，顯示到小數點後一位
    printf("Value of expression: %.1f\n", result);
    return 0;
}
