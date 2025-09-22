// 計算四個整數的平均值
#include <stdio.h>
// 函數原型
double calculateAverage(int number[]);
int main() {
    int number[4]={0}; // 宣告一個整數陣列來存放四個數字
    for(int i=0;i<4;i++){
        scanf("%d", &number[i]); // 讀取四個整數
    }
    /* 或者你也可以不用for迴圈 直接寫成
    scanf("%d %d %d %d", &number[0], &number[1], &number[2], &number[3]);*/
    // 計算平均值並輸出結果
    double average = calculateAverage(number);
    printf("%.2f\n", average);

    return 0;
}

double calculateAverage(int number[]) {

    int sum = 0;
    for(int i=0;i<4;i++){
        sum += number[i]; // 計算總和
    }
    return (double)sum / 4; // 計算並返回平均值
}