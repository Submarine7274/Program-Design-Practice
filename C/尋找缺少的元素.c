#include <stdio.h>
int main(void) {
    int n, sum = 0, an;

    // 輸入數組的大小
    scanf("%d", &n);

    int arr[n];

    // 輸入數組元素
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < (n - 1); i++) {
        sum += arr[i];
    }
    an = ((1 + n) * n  / 2 );
     
    printf("%d", an - sum);

    return 0;
}