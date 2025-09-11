#include<stdio.h>
int main (void){
    float tax, inccome;  //宣告稅額與收入變數
    printf("Enter amount of taxable income: "); //提示輸入收入
    scanf("%f", &inccome);  //讀取收入
    if(inccome < 750){  //根據收入範圍計算稅額
        tax = inccome * 0.01f;  //收入小於750，稅率1% 那個f是告訴編譯器這是float
    }
    else if (inccome < 2250){
        tax = 7.5f + (inccome - 750) * 0.02f;   //收入在750到2250之間，稅率2%，前750的稅額是7.5
    }
    else if (inccome < 3750){
        tax = 37.5f + (inccome - 2250) * 0.03f;  //收入在2250到3750之間，稅率3%，前2250的稅額是37.5
    }
    else if (inccome < 5250){
        tax = 82.5f + (inccome - 3750) * 0.04f; //收入在3750到5250之間，稅率4%，前3750的稅額是82.5
    }
    else if (inccome <= 7000){
        tax = 142.5f + (inccome - 5250) * 0.05f;    //收入在5250到7000之間，稅率5%，前5250的稅額是142.5
    }
    else{
        tax = 230 + (inccome - 7000) * 0.06f;   //收入超過7000，稅率6%，前7000的稅額是230
    }
    printf("Tax due is: $%.2f",tax);    //輸出稅額，保留兩位小數
    return 0;
}