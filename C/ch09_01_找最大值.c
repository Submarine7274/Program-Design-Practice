#include <stdio.h>

// 函數原型
int findMax(int a, int b);

int main() {
    int num1, num2;

    // 輸入兩個整數
    //printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // 調用函數找出最大值並顯示
    int max = findMax(num1, num2);
    printf("%d", max);

    return 0;
}

// 函數定義：找出兩個整數的最大值
int findMax(int a, int b) {
    return (a > b) ? a : b;
}