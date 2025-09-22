#include <stdio.h>
int main (void){
    int number, sum = 0;
    while(1){
        scanf("%d", &number);   //讀取輸入的數字
        if(number < 0 ){    //如果輸入的數字是負數
            continue;   //跳過本次迴圈 進入下一次迴圈
        }
        else if(number > 0){    //如果輸入的數字是正數
            sum += number;  //將正數加到總和中
        }
        else if (number == 0){  //如果輸入的數字是0
            break;  //跳出迴圈 結束輸入
        }
    }
    printf("%d", sum);  //輸出正數的總和
    return 0;
}