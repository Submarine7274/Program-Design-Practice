#include <stdio.h>

// 函數原型
void countdown(int n);

int main() {
    int N;

    // 輸入正整數 N
    //printf("Enter a positive integer N: ");
    scanf("%d", &N);

    // 調用函數顯示倒數結果
    countdown(N);

    return 0;
}

// 函數定義：顯示從 n 倒數至 0 的結果
void countdown(int n) {
    for (int i = n; i >= 0; i--) {
        printf("%d\n", i);
    }
}