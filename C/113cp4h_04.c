#include <stdio.h>
int main (void){
    int number=0, digit[5]={0};
    printf("Enter a number between 0 and 32767:");
    scanf("%d", &number);
    //printf("In octal, your number is:%05o", num); Ｃ其實可以直接輸出八進位 這一行就可以完成題目
    for (int i = 0; i<= 4; i++){    //這種做法是傳統的轉進位方式 用除的 用陣列存放每一位數
        digit[i]= number % 8;  //除8取餘數
        number /=8;    //除8取商
    }
    printf("In octal, your number is:%01d%01d%01d%01d%01d",digit[4], digit[3], digit[2], digit[1], digit[0]); //輸出陣列的值 要注意每個位數的位置
    return 0;
}