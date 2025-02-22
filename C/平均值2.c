#include <stdio.h>

// 函數原型
double calculateAverage(int num1, int num2, int num3);

int main() {
    int num1, num2, num3;

    // 輸入三個數字
    //printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // 計算平均值並輸出結果
    double average = calculateAverage(num1, num2, num3);
    printf("%.2f\n", average);

    return 0;
}

// 函數定義：計算三個數字的平均值
double calculateAverage(int num1, int num2, int num3) {
    return (num1 + num2 + num3) / 3.0;
}
