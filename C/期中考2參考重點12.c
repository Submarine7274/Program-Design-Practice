#include <stdio.h>

// 函數：計算 Fibonacci 數列的第 n 項
int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    while (1) {
        // 提示使用者輸入
        printf("Enter an integer (or -1 to exit): ");
        scanf("%d", &n);

        if (n == -1) {
            // 使用者輸入 -1，退出程式
            break;
        } else if (n < 0) {
            // 輸入錯誤，請求重新輸入正整數
            printf("Please enter a non-negative integer.\n");
        } else {
            // 計算 Fibonacci 數列的第 n 項並輸出
            int result = fibonacci(n);
            printf("Fibonacci(%d) = %d\n", n, result);
        }
    }

    printf("Program exited.\n");

    return 0;
}
