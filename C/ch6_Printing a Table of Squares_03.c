#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial = 1;
    unsigned long long sum = 0;
    double e = 1.0;
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        factorial *= i;
        sum += factorial;
        e += 1.0 / sum;
    }
    printf("%.4f",e);
    return 0;
}