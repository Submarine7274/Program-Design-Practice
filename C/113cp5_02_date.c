#include <stdio.h>
int main (void){
    int mm, dd, yy;
    printf("Enter date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm, &dd, &yy);
    printf("Dated this %d", dd);
    if(dd ==1|| dd ==21|| dd==31){
        printf("st day of ");
    }
    else if (dd ==2|| dd ==22){
        printf("nd day of ");
    }
    else if (dd ==3|| dd ==23){
        printf("rd day of ");
    }
    else{
        printf("th day of ");
    }
    switch(mm){
        case 1:
        printf("January, 20%02d.", yy);
        break;
        case 2:
        printf("Febuary, 20%02d.", yy);
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
        printf("error");
    }
    return 0;
}