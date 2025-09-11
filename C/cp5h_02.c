#include<stdio.h>
int main (void){
    int hour, minute;   //宣告小時與分鐘變數
    printf("Enter a 24-hour time: ");   //提示輸入24小時制時間
    scanf("%2d:%2d", &hour, &minute);   //讀取24小時制時間
    if (hour >= 0 && hour < 24 && minute >= 0 && minute <= 59){ //判斷輸入時間是否在正確範圍內
        if(hour > 12){  //根據小時範圍判斷並轉換為12小時制時間 如果大於12則減去12並輸出PM
            hour -= 12;
            printf("Equivalent 12-hour time: %2d:%02d PM", hour, minute);
        }
        else if(hour == 12){    //如果等於12則輸出PM
            printf("Equivalent 12-hour time: %2d:%02d PM", hour, minute);
        }
        else if(hour < 12 && hour > 0){ //如果小於12且大於0則輸出AM
            printf("Equivalent 12-hour time: %2d:%02d AM", hour, minute);
        }
        else if(hour == 0){ //如果等於0則轉換為12並輸出AM
            hour = 12;
            printf("Equivalent 12-hour time: %2d:%02d AM", hour, minute);
        }
    }
    else{
        printf("Not the correct time format");  //如果輸入時間不在正確範圍內 則輸出錯誤訊息
    }
    return 0;
}