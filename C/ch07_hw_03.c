#include<stdio.h>
#include<ctype.h>
int main(void){
    int h, m;
    char t[4];
    printf("Enter a 12-hour time (hours:minutes AM/PM): \n");
    scanf("%d:%d%s",&h ,&m ,t);
    for (int i = 0; t[i]; i++) {
        t[i] = toupper(t[i]); // 將 AM 或 PM 轉為大寫
    }
    if (t[0] == 'P' && h < 12) {
        h += 12;
    }
    printf("Equivalent 24-hour time: %02d:%02d", h, m);
    return 0;
}