#include <stdio.h>

int main(void) {
    int mm, dd, yy, h, m, s;
    
    scanf("%2d/%2d/%2d", &mm, &dd, &yy);
    scanf("%2d:%2d:%2d", &h, &m, &s);
    if (h > 12){
        h -= 12;
        printf("PM %02d", h);
    }
    else if(h == 12){
        h = 12;
        printf("PM %02d", h);
    }
    else if(h == 0){
        h = 12;
        printf("AM %02d", h);
    }
    else{
        printf("AM %02d", h);
    }
    printf(":%02d",m);
    printf(":%02d,",s);
    printf(" %d", dd);
    
    switch (dd) {
        case 1: case 21: case 31:
            printf("st"); break;
        case 2: case 22:
            printf("nd"); break;
        case 3: case 23:
            printf("rd"); break;
        default: printf("th"); break;
    }
    printf(" day of ");
    switch (mm) {
        case 1:  printf("January");   break;
        case 2:  printf("February");  break;
        case 3:  printf("March");     break;
        case 4:  printf("April");     break;
        case 5:  printf("May");       break;
        case 6:  printf("June");      break;
        case 7:  printf("July");      break;
        case 8:  printf("August");    break;
        case 9:  printf("September"); break;
        case 10: printf("October");   break;
        case 11: printf("November");  break;
        case 12: printf("December");  break;
    }
    printf(", 20%02d.", yy);
    return 0;
}