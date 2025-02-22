#include <stdio.h>

// 函數原型
double calculateAverage(int num1, int num2, int num3, int num4);

int main() {
    int num1, num2, num3, num4;
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    // 計算平均值並輸出結果
    double average = calculateAverage(num1, num2, num3, num4);
    printf("%.2f\n", average);

    return 0;
}

double calculateAverage(int num1, int num2, int num3, int num4) {
    return (num1 + num2 + num3 + num4) / 4.0;
}