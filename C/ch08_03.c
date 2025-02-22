#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool digit_seen[10] = {false}; // 用來追蹤數字是否已經出現過
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10; // 取得最後一位數字

        if (digit_seen[digit]) {
            printf("Repeated digit\n");
            return 0;
        }

        digit_seen[digit] = true; // 將該數字標記為已經出現
        n /= 10; // 移除最後一位數字
    }

    printf("No repeated digit\n");

    return 0;
}