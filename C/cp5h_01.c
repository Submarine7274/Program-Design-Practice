#include<stdio.h>
int main (void){
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    if(i <= 9 && i >= 1){
        printf("The number %d has 1 digit", i);
    }
    else if(i <= 99 && i >= 10){
        printf("The number %d has 2 digits", i);
    }
    else if(i <= 999 && i >= 100){
        printf("The number %d has 3 digits", i);
    }
    else if(i <= 9999 && i >= 1000){
        printf("The number %d has 4 digits", i);
    }
    else{
        printf("Please enter the whole between 1 and 9999");
    }
return 0;}