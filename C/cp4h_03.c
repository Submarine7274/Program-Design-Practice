#include<stdio.h>
int main(void)
{
    int d2, d1, d;
    printf("Enter a three-digit number:");
    scanf("%1d%1d%1d", &d2, &d1, &d);
    printf("The reversal is %01d %01d %01d", d, d1, d2);
    return 0;
}