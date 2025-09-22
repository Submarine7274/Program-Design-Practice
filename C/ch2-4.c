#include <stdio.h>
int main (void){   
    int money=0, twentyDollars=0, tenDollars=0, fiveDollars=0, oneDollars=0;  //宣告總金額 20元 10元 5元 1元變數
    scanf("%d", &money);    //輸入總金額
    twentyDollars = money / 20; //計算20元張數
    tenDollars = (money % 20) / 10; //計算10元張數
    fiveDollars = ((money % 20) % 10) / 5;  //計算5元張數
    oneDollars = ((money % 20) % 10) % 5;       //計算1元張數
    printf("%d %d %d %d", twentyDollars, tenDollars, fiveDollars, oneDollars);  //輸出結果
    return 0;
}