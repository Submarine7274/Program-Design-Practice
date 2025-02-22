#include <stdio.h>

// 尾遞迴輔助函數
int countWaysTailRec(int n, int currentSum, int currentWay);

// 函數原型
int countWays(int n);

int main() {
    int n;

    // 提示用戶輸入正整數 n
    //printf("請輸入一個正整數 n：");
    scanf("%d", &n);

    if (n <= 0) {
        printf("請輸入正整數。\n");
        return 1; // 返回錯誤碼
    }

    // 輸出分解方式數量
    printf("%d", countWays(n));

    return 0;
}

// 尾遞迴函數
int countWaysTailRec(int n, int currentSum, int currentWay) {
    if (currentSum == n) {
        return currentWay + 1; // 達到目標值，返回當前方式數量
    } else if (currentSum > n) {
        return currentWay; // 超過目標值，返回當前方式數量
    }

    // 遞迴呼叫
    return countWaysTailRec(n, currentSum + 1, currentWay) + countWaysTailRec(n, currentSum + 2, currentWay);
}

// 開始尾遞迴的函數
int countWays(int n) {
    return countWaysTailRec(n, 0, 0);
}
