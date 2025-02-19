#include <stdio.h>
int main (void){
    int num=0, d1=0, d2=0, d3=0;
    printf("Enter a three-digit number:");
    scanf("%d", &num);
    d3 = num % 10;
    num /= 10;
    d2 = num % 10;
    d1 = num / 10;
    printf("The reversal is %1d%1d%1d", d3, d2, d1);
    return 0;
}