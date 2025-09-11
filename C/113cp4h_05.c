#include <stdio.h>
int main (void){
    int numbers[11]={0}, evensum = 0, oddsum = 0, checkdegit = 0;   //陣列存放11個數 evensum偶數位數總和 oddsum奇數位數總和 checkdegit檢查碼 都初始化為0
    printf("Enter the first 11 digits of a UPC:");  //輸出提示
    for(int i = 0; i <= 10; i++){   //輸入11個數字
        scanf("%1d", &numbers[i]);
    }
    for(int i = 0; i<=10; i++){  //計算偶數位數總和與奇數位數總和
        if (i % 2 == 0){    //偶數位數
            evensum += numbers[i];  //+=是加上數字後再賦值給自己 (等同於 evensum = evensum + numbers[i];)
        }
        else{   //奇數位數
            oddsum += numbers[i];
        }
    }
    checkdegit = 9 -((((evensum*3) +oddsum) -1) %10); //計算檢查碼
    printf("Check digit:%d", checkdegit);   //輸出檢查碼
    return 0;
}