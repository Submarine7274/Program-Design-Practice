//利用牛頓法計算平方根
#include <stdio.h>
#include <math.h>
int main (void){
    double number = 0.0f, estimate = 1.0f, nextEstimate = 0.0f; //宣告雙精度浮點數 數字 初始估計值 下一次估計值
    printf("Enter a positive number: ");
    scanf("%lf", &number);  //讀取使用者輸入的數字
    do{ //利用牛頓法計算平方根 用do while迴圈確保執行一次 
        nextEstimate = (estimate + (number/estimate)) /2;   //計算下一次估計值是 (估計值 + (數字/估計值)) /2
         //判斷兩次估計值的差是否小於0.0001*估計值 若是則跳出迴圈
        if(fabs(nextEstimate -estimate)< 0.0001 *estimate){ //
            break;
        }
        estimate = nextEstimate;    //將下一次估計值指定給估計值
    }while(1);
    
    printf("Square root: %.5f", nextEstimate);  //輸出平方根結果
    return 0;
}