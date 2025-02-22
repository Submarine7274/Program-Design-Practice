#include<stdio.h>

int summation(int n, int ans) {
    if (n == 0) {
        return ans;
    } else {
        printf("summation(%d,%d)\n",n - 1, ans + n);
        return summation(n - 1, ans + n);
    }
}

int main() {
    int n;
    int sum;
    scanf("%d", &n);
    sum = summation(n, 0);
    printf("%d", sum);
    return 0;
}