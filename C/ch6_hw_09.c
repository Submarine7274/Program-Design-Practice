#include<stdio.h>
//計算 e 的近似值
// e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
#include <stdio.h>

int main(void) {
    int number = 0, factorial = 1;        // factorial 用於計算階乘
    float eApproximation = 1.0;  // eApproximation = e 的近似值

    scanf("%d", &number);

    if (number >= 1 && number <= 7) {   // 限制輸入範圍
        for (int i = 1; i <= number; ++i) {
            factorial *= i;                        // 計算 i!
            eApproximation += 1.0 / factorial;     // 累加 1/i!
        }
        printf("%.4f", eApproximation);            // 輸出近似值
    } else {
        printf("Input must be between 1 and 7");   // 超出範圍的提示
    }

    return 0;
}
