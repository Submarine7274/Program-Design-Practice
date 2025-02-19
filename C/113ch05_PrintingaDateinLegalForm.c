#include <stdio.h>
int main (void){
    int mm, dd, yy;
    printf("Enter date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm, &dd, &yy);
    printf("Dated this ");
    if(dd == 1 || dd == 21 || dd == 31){
        printf("%dst day of ", dd);
    }
    else if(dd == 2 || dd == 22){
        printf("%dnd day of ", dd);
    }
    else if(dd == 3 || dd == 23){
        printf("%drd day of ", dd);
    }
    else{
        printf("%dth day of ", dd);
    }
    if(mm == 1){
        printf("January");
    }
    else if(mm == 2){
        printf("February");
    }
    else if(mm == 3){
        printf("March");
    }
    else if(mm == 4){
        printf("April");
    }
    else if(mm == 5){
        printf("May");
    }
    else if(mm == 6){
        printf("June");
    }
    else if(mm == 7){
        printf("July");
    }
    else if(mm == 8){
        printf("August");
    }
    else if(mm == 9){
        printf("September");
    }
    else if(mm == 10){
        printf("October");
    }
    else if(mm == 11){
        printf("November");
    }
    else if(mm == 12){
        printf("December");
    }
    printf(", 20%d.", yy);
    return 0;
}