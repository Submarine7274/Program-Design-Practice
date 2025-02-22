#include <stdio.h>

int main(void) {
    int a[5], b[5] = {90, 80, 70, 60, 0}, i;
    int max_a = 0; // 初始化最大值

    // 輸入 a 陣列的值並找出最大值
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max_a) {
            max_a = a[i];
        }
    }

    // 使用最大值比較
    if (max_a >= b[0]) {
        printf("A");
    } else if (max_a >= b[1]) {
        printf("B");
    } else if (max_a >= b[2]) {
        printf("C");
    } else if (max_a >= b[3]) {
        printf("D");
    } else if (max_a >= b[4]) {
        printf("E");
    }

    return 0;
}
