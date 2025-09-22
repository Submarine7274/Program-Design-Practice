#include <stdio.h>
int main (void) {
    float loan, interestRate, monthlyInterestRate, monthlyPayment, balance1, balance2, balance3;    //宣告貸款金額 年利率 月利率 月付款 第1個月餘額 第2個月餘額 第3個月餘額
    scanf("%f", &loan);   //輸入貸款金額 年利率 月付款
    scanf("%f", &interestRate);
    scanf("%f", &monthlyPayment);
    monthlyInterestRate = interestRate / 12 /100 +1;    //計算月利率
    balance1 = loan * monthlyInterestRate - monthlyPayment;  //計算每個月餘額
    balance2 = balance1 * monthlyInterestRate - monthlyPayment;     
    balance3 = balance2 * monthlyInterestRate - monthlyPayment;
    printf("$%.2f\n$%.2f\n$%.2f", balance1, balance2, balance3);    //輸出結果
    return 0;
}