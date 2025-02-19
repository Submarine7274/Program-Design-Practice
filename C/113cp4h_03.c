#include <stdio.h>
int main (void){
    int d1=0, d2=0, d3=0;
    printf("Enter a three-digit number:");
    scanf("%1d%1d%1d", &d1, &d2, &d3);
    printf("The reversal is %01d %01d %01d", d3, d2, d1);
    return 0;
}