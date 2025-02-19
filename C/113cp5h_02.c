#include <stdio.h>
int main (void){
    int hours, minutes;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);
    if(hours>23 ||hours <0||minutes >60|| minutes<0){
        printf("Not the correct time format");
    }
    else if(hours > 12 && hours <24){
        hours -=12;
        printf("Equivalent 12-hour time: %d:%02d PM",hours, minutes);
    }
    else if(hours == 12){
        printf("Equivalent 12-hour time: %d:%02d PM",hours, minutes);
    }
    else if(hours == 0){
        hours = 12;
        printf("Equivalent 12-hour time: %d:%02d AM",hours, minutes);
    }
    else if(hours <12){
        printf("Equivalent 12-hour time: %d:%02d AM",hours, minutes);
    }
    return 0; 
}