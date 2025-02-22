#include <stdio.h>
#include <ctype.h>
int main (void){
    int hours, minutes;
    char meridiem[4];
    printf("Enter a 12-hour time (hours:minutes AM/PM): ");
    scanf("%d:%d%s", &hours, &minutes, meridiem);
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