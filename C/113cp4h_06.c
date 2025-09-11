#include <stdio.h>
int main (void){
    int numbers[13]={0}, evensum = 0, oddsum = 0, checkdigit = 0;   //陣列存放13個數 evensum偶數位數總和 oddsum奇數位數總和 checkdigit檢查碼 都初始化為0
    printf("Enter the first 12 digits of an EAN:"); //輸出提示
    for(int i = 0; i <= 11; i++){
        scanf("%1d", &numbers[i]);  //輸入12個數字
    }
    for(int i = 0; i<=12; i++){
        if (i % 2 == 1 && i <= 11){   //奇數位數 且不包含檢查碼
            oddsum += numbers[i];
        }
        else if(i <= 10){
            evensum += numbers[i];  //偶數位數 且不包含檢查碼
        }
    }
    checkdigit = 9 -((((oddsum*3) +evensum) -1) %10);   //計算檢查碼
    printf("Check digit:%d", checkdigit);   //輸出檢查碼
    return 0;
}