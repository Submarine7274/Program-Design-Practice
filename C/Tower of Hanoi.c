#include <stdio.h>

// 函數原型
void hanoi(int n, int source, int target, int auxiliary, int *moves);

int main() {
    int n, moves = 0;

    scanf("%d", &n);

    // 呼叫 hanoi 函數解 Tower of Hanoi 問題
    hanoi(n, 1, 3, 2, &moves);

    // 輸出總移動次數
    printf("%d", moves);

    return 0;
}

// 使用尾遞歸計算 Tower of Hanoi 問題的函數
void hanoi(int n, int source, int target, int auxiliary, int *moves) {
    if (n > 0) {
        // 移動 n-1 個盤子到輔助柱
        hanoi(n - 1, source, auxiliary, target, moves);

        // 移動第 n 個盤子到目標柱
        printf("Move disk %d from pole %d to pole %d\n", n, source, target);
        (*moves)++;

        // 移動輔助柱上的 n-1 個盤子到目標柱
        hanoi(n - 1, auxiliary, target, source, moves);
    }
}
