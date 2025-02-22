#include <stdio.h>

double power(double c, double e);  // 使用 long long int

int main(void) {
    double coe, exp;  // 使用 long long int
    scanf("%lf %lf", &coe, &exp);  // 使用 %lld 格式來讀取 long long int
    printf("%.0lf", power(coe, exp));  // 使用 %lld 格式來打印 long long int
    return 0;
}

double power(double c, double e) {
    if (e == 0) {
        return 1;
    } else {
        return c * power(c, e - 1);
    }
}
