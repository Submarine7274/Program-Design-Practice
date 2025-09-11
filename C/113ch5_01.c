#include <stdio.h>
int main (void){
    int number=0; //宣告使用者輸入的數字變數
    const char* month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; //宣告字串陣列存放月份
    scanf("%d", &number); //輸入數字
    if(number > 12 || number <= 0){     //檢查輸入數字是否在1~12之間
        printf("error"); //輸入錯誤輸出error
    }
    else {
        number -= 1;    //陣列是從0開始 所以要-1
        printf("%s", month[number]);    //輸出對應的月份
    }
    return 0;
}