#include <stdio.h>
int main (void){
    int mon, dd, yy, hh, min, ss;
    scanf("%d/%d/%d", &mon, &dd, &yy);
    scanf("%2d:%2d:%2d", &hh, &min, &ss);
    if(hh == 0){
        hh = 12;
        printf("AM %02d:%02d:%02d, ", hh, min, ss);
    }
    else if(hh <12){
        printf("AM %02d:%02d:%02d, ", hh, min, ss);
    }
    else if(hh == 12){
        printf("PM %02d:%02d:%02d, ", hh, min, ss);
    }
    else if(hh > 12){
        hh -= 12;
        printf("PM %02d:%02d:%02d, ", hh, min, ss);
    }
    
    if(dd == 1|| dd == 21|| dd == 31){
        printf("%dst day of ", dd);
    }
    else if(dd == 2|| dd == 22){
        printf("%dnd day of ", dd);
    }
    else if(dd == 3|| dd == 23){
        printf("%drd day of ", dd);
    }
    else{
        printf("%dth day of ", dd);
    }
    switch (mon){
        case 1:
        printf("January, 20%02d.", yy);
        break;
        case 2:
        printf("February, 20%02d.", yy);
        break;
        case 3:
        printf("March, 20%02d.", yy);
        break;
        case 4:
        printf("April, 20%02d.", yy);
        break;
        case 5:
        printf("May, 20%02d.", yy);
        break;
        case 6:
        printf("June, 20%02d.", yy);
        break;
        case 7:
        printf("July, 20%02d.", yy);
        break;
        case 8:
        printf("August, 20%02d.", yy);
        break;
        case 9:
        printf("September, 20%02d.", yy);
        break;
        case 10:
        printf("October, 20%02d.", yy);
        break;
        case 11:
        printf("November, 20%02d.", yy);
        break;
        case 12:
        printf("December, 20%02d.", yy);
        break;
        default:
        printf("%d, 20%d", yy);
        break;
    }
    return 0;
}