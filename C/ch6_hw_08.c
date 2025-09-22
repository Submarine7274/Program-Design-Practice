#include<stdio.h>
int main (void){
    int daysInMonth, day, startDay, spaceCount; // 宣告變數 一個月有幾天、日期、1號是星期幾、空格計數器
    
    scanf("%d", &daysInMonth);   // 讀取這個月的天數
    scanf("%d", &startDay);      // 讀取這個月1號是星期幾
    
    for (spaceCount = 1; spaceCount < startDay; spaceCount++){  // 印出1號前的空格
        printf("   ");
    }

    for (day = 1; day <= daysInMonth; day++){   // 印出日期
        printf("%3d", day); // 每個日期佔3個字元寬度
         // 換行條件：1. 當前日期加上起始星期幾減1後能被7整除 2. 當前日期等於這個月的最後一天
        if ((day + startDay - 1) % 7 == 0 || day == daysInMonth ) {
            printf("\n");
        }
    }
    return 0;
}