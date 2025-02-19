#include <stdio.h>
int main (void){
    int windSpeed;
    printf("Enter wind speed (knots): ");
    scanf("%d", &windSpeed);
    if(windSpeed<0){
        printf("error");
    }
    else{
        if(windSpeed<1){
            printf("Wind force at %d knots is Calm", windSpeed);
        }
        else if(windSpeed>=1 && windSpeed<=3){
            printf("Wind force at %d knots is Light air", windSpeed);
        }
        else if(windSpeed>=4 && windSpeed<=27){
            printf("Wind force at %d knots is Breeze", windSpeed);
        }
        else if(windSpeed>=28 && windSpeed<=47){
            printf("Wind force at %d knots is Gale", windSpeed);
        }
        else if(windSpeed>=48 && windSpeed<=63){
            printf("Wind force at %d knots is Storm", windSpeed);
        }
        else{
            printf("Wind force at %d knots is Hurricane", windSpeed);
        }
    }
    return 0;
}