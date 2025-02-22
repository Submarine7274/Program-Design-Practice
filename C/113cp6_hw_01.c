#include <stdio.h>
int main (void){
    float number=-1.0, greatest=0.0;
    while(number !=0){
        printf("Enter a number (enter 0 to end): ");
        scanf("%f", &number);
        if(number >=greatest){
            greatest = number;
        }
    }
    printf("The largest number entered was %.2f", greatest);
    return 0;
}