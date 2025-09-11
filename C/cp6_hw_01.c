#include<stdio.h>
int main (void){
    float number = -1, maxnumber = 0;   //宣告輸入的數字與最大值變數
    while(number != 0){ //當輸入的數字不為0時持續執行迴圈
        printf("Enter a number (enter 0 to end): \n");  //提示輸入數字
        scanf("%f", &number);   //讀取輸入的數字 %f表示讀取浮點數
        if(number >= maxnumber){   //如果輸入的數字大於或等於目前的最大值
            maxnumber = number;  //將輸入的數字設為新的最大值
        }
    }
    printf("The largest number entered was %.2f", maxnumber);   //輸出最大值 %.2f表示輸出浮點數且保留兩位小數
    return 0;
}