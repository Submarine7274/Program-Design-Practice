#include <stdio.h>
#include <ctype.h>
int main (void){
    int hours, minutes; //宣告變數 小時與分鐘
    char meridiem[4];   //宣告變數 AM或PM
    printf("Enter a 12-hour time (hours:minutes AM/PM): ");  //提示輸入
    scanf("%d:%d%s", &hours, &minutes, meridiem);   //讀取輸入的時間
    //將輸入的AM或PM轉成大寫以便比較
    for(int i = 0; meridiem[i]; i++){
        meridiem[i] = toupper(meridiem[i]);
    }
    if(meridiem[0] == 'P'&& hours <12){
        hours += 12;
    }
    else if(meridiem[0] == 'A' && hours == 12){
        hours = 0;
    }
    printf("Equivalent 24-hour time: %02d:%02d", hours, minutes);
    return 0;
}