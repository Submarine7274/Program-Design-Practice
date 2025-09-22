#include <stdio.h>
int main(void) {
    int entryCount, square; // 宣告變數 表格條目數、平方值
    printf("This program prints a table of squares.\n");    // 說明程式功能
    printf("Enter number of entries in table: ");   // 提示使用者輸入條目數
    scanf("%d", &entryCount);   // 讀取條目數
    for (int i = 1; i <= entryCount; ++i) { // 從1到條目數迴圈
        square = i * i; // 計算平方值
         // 印出條目數及其平方值，欄位寬度為10
        printf("%10d%10d\n", i, square);    
    }
    return 0;
}