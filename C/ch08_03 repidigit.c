#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool digit_seen[10] = {false};  // 用來記錄每個數字是否已經出現過
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;            // 取出最後一位數
        if (digit_seen[digit]) {   // 檢查該位數是否已經出現過
            printf("Repeated digit\n");
            return 0;
        }
        digit_seen[digit] = true;  // 標記該數字已出現過
        n /= 10;                   // 移除最後一位數
    }

    printf("No repeated digit\n");
    return 0;
}
