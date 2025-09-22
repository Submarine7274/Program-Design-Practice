#include <stdio.h>
#define FREEZING_PT 32.0f   //華氏的冰點 這是預先定義 這樣下面可以直接用
#define SCALE_FACTOR (9.0f / 5.0f)  //攝氏轉華氏的比例 這是預先定義
int main (void){
    float fahrenheit, celsius;  //宣告華氏 攝氏變數
    scanf("%f", &celsius);  //輸入攝氏溫度
    fahrenheit = (celsius * SCALE_FACTOR) + FREEZING_PT;    //計算華氏溫度
    printf("%.2f", fahrenheit); //輸出華氏溫度到小數點後兩位
    return 0;
}