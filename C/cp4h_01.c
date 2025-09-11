#include <stdio.h>
int main (void){
    int number=0, digit1=0, digit2=0;   //宣告輸入的數字與兩個位數變數
    printf("Enter a two-digit number:");    //提示輸入兩位數
    scanf("%d", &number);   //讀取兩位數
    digit2 = number % 10;   //個位數是數字除以10的餘數
    digit1 = number / 10;   //十位數是數字除以10的商數
    printf("The reversal is %1d%1d", digit2, digit1);       //輸出反轉後的數字  
    return 0;
}