#include<stdio.h>
int main (void){
    int numerator1, numerator2, numerator3, denominator1, denominator2, denominator3, numerator4, denominator4; //宣告分子 分母變數
    scanf("%d/%d", &numerator1, &denominator1); //輸入分數1
    scanf("%d/%d", &numerator2, &denominator2); //輸入分數2
    scanf("%d/%d", &numerator3, &denominator3); //輸入分數3
    numerator4 = (numerator1 * denominator2 *denominator3) + (numerator2 * denominator1 * denominator3) + (numerator3 * denominator1 *denominator2);    //計算分子 通分且不考慮約分
    denominator4 = denominator1 * denominator2 * denominator3;  //計算分母
    printf("%d/%d", numerator4, denominator4);  //輸出結果
    return 0;
}