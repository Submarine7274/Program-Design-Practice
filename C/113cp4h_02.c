#include <stdio.h>
int main (void){
    int number=0, d1=0, d2=0, d3=0;
    printf("Enter a three-digit number:");
    scanf("%d", &number);
    d3 = number % 10;
    number /= 10;
    d2 = number % 10;
    d1 = number / 10;
    printf("The reversal is %1d%1d%1d", d3, d2, d1);
    return 0;
}