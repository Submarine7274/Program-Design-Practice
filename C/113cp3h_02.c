#include <stdio.h>
int main (void){
    int n1, n2, n3; //宣告三個整數變數
    scanf("(%2d) %4d-%4d", &n1, &n2, &n3);  //依指定格式輸入三個整數
    printf("You entered %02d.%4d.%4d", n1, n2, n3); //依指定格式輸出三個整數
    return 0;   //程式結束
}