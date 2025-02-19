#include <stdio.h>
int main (void){
    int num=0, d1=0, d2=0;
    printf("Enter a two-digit number:");
    scanf("%d", &num);
    d2 = num % 10;
    d1 = num / 10;
    printf("The reversal is %1d%1d", d2, d1);
    return 0;
}