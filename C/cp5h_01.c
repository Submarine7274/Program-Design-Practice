#include<stdio.h>
int main (void){
    int number;  //宣告number變數
    printf("Enter a number: ");  //提示輸入數字
    scanf("%d", &number);   //讀取輸入數字
     //根據number範圍判斷並輸出位數 
    if(number <= 9 && number >= 1){
        printf("The number %d has 1 digit", number);
    }
    else if(number <= 99 && number >= 10){
        printf("The number %d has 2 digits", number);
    }
    else if(number <= 999 && number >= 100){
        printf("The number %d has 3 digits", number);
    }
    else if(number <= 9999 && number >= 1000){
        printf("The number %d has 4 digits", number);
    }
    else{
        printf("Please enter the whole between 1 and 9999");    //如果輸入數字不在1~9999範圍內 則輸出錯誤訊息
    }
    return 0;
}