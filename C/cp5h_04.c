#include<stdio.h>
int main (void){
    int s;
    printf("Enter wind speed (knots): ");
    scanf("%d", &s);
    if(s < 1){
        printf("Wind force at %d knots is Calm", s);
    }
    else if(s >= 1 && s <= 3 ){
        printf("Wind force at %d knots is Light air", s);
    }
    else if(s >= 4 && s <= 27 ){
        printf("Wind force at %d knots is Breeze", s);
    }
    else if(s >= 28 && s <= 47 ){
        printf("Wind force at %d knots is Gale", s);
    }
    else if(s >= 48 && s <= 63 ){
        printf("Wind force at %d knots is Storm", s);
    }
    else if(s > 63 ){
        printf("Wind force at %d knots is Hurricane", s);
    }
return 0;
}