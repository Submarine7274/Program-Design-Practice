#include <stdio.h>
#include <math.h>

int main(void) {
    double principal = 100.0;
    double rate;
    int years;

    // 使用者輸入
    printf("Enter interest rate: ");
    scanf("%lf", &rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    // 表頭
    printf("\nYears");
    for (int i = 0; i < 5; i++) {
        printf("%6.0f%%", rate + i);
    }
    printf("\n");

    // 表格內容
    for (int year = 1; year <= years; year++) {
        printf("%3d    ", year);

        for (int i = 0; i < 5; i++) {
            double interest_rate = rate + i;
            double amount = principal * pow(1 + interest_rate / 100, year);
            printf(" %.2f", amount);
        }

        printf("\n");
    }

    return 0;
}