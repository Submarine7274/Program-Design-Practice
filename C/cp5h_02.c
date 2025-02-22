#include<stdio.h>
int main (void){
    int h, m;
    printf("Enter a 24-hour time: ");
    scanf("%2d:%2d", &h, &m);
    if (h >= 0 && h < 24 && m >= 0 && m <= 59)
    {
    if(h > 12){
        h -= 12;
        printf("Equivalent 12-hour time: %2d:%02d PM", h, m);
    }
    else if(h == 12){
        printf("Equivalent 12-hour time: %2d:%02d PM", h, m);
    }
    else if(h < 12 && h > 0){
        printf("Equivalent 12-hour time: %2d:%02d AM", h, m);
    }
    else if(h == 0){
        h = 12;
        printf("Equivalent 12-hour time: %2d:%02d AM", h, m);
    }
    }
    else{
        printf("Not the correct time format");
        }
    return 0;
}