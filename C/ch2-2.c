//整數變數跟浮點數變數的練習 
#include<stdio.h>
int main (void){
    int x;  //宣告整數變數
    float y;    //宣告浮點數變數
    scanf("%d", &x);    //輸入整數
    y = x *1.05;    //計算浮點數
    printf("%.2f", y);  //輸出浮點數到小數點後兩位
    return 0;
}