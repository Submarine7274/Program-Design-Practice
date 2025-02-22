#include <stdio.h>
int main (void){
    int min =0, hh=0, rmin=0;
    scanf("%d", &min);
    hh = min /60;
    rmin = min %60;
    if(hh == 0){
        hh = 12;
        printf("AM:");
    }
    else if(hh == 24){
        hh -= 12;
        printf("AM:");
    }
    else if(hh <12){
        printf("AM:");
    }
    else if(hh == 12){
        printf("PM:");
    }
    else if(hh > 12){
        hh -= 12;
        printf("PM:");
    }
    switch(hh){
        case 1:
        printf("one:%d", rmin);
        break;
        case 2:
        printf("two:%d", rmin);
        break;
        case 3:
        printf("three:%d", rmin);
        break;
        case 4:
        printf("four:%d", rmin);
        break;
        case 5:
        printf("five:%d", rmin);
        break;
        case 6:
        printf("six:%d", rmin);
        break;
        case 7:
        printf("seven:%d", rmin);
        break;
        case 8:
        printf("eight:%d", rmin);
        break;
        case 9:
        printf("nine:%d", rmin);
        break;
        case 10:
        printf("ten:%d", rmin);
        break;
        case 11:
        printf("eleven:%d", rmin);
        break;
        case 12:
        printf("twelve:%d", rmin);
        break;
    }
}