#include <stdio.h>
int main (void){
    int number[12],checkDigit,evenSum,oddSum;   //宣告number陣列與checkDigit,evenSum,oddSum變數
    printf("Enter the first 12 digits of an EAN:"); //提示輸入EAN碼前12位數字
    for(int i=0;i<12;i++){  //使用迴圈讀取12位數字並存入number陣列
        scanf("%1d",&number[i]);
    }
    evenSum=number[1]+number[3]+number[5]+number[7]+number[9]+number[11];   //計算偶數位數字總和 陣列是從0開始 所以偶數位是1,3,5,7,9,11
    oddSum=number[0]+number[2]+number[4]+number[6]+number[8]+number[10];    //計算奇數位數字總和 陣列是從0開始 所以奇數位是0,2,4,6,8,10
    checkDigit=9-(((3*evenSum)+oddSum-1)%10);   //計算檢查碼
    printf("Check digit:%d",checkDigit);    //輸出檢查碼
    return 0;
}