/*這題目我已經忘了 總之就是算體積跟重量 請自行調整數值*/
#include <stdio.h>
int main (void){
    int height, length, width, volume, weight;  //宣告高度 長度 寬度 體積 重量
    height = 12;    //給定高度 長度 寬度
    length = 14;
    width= 11;
    volume = height * length * width;   //計算體積
    weight = (volume +99) /100; //計算重量 這邊是無條件進位
    printf("%d", weight);   //輸出重量
    return 0;
}