#include<stdio.h>
int main (void)
{
    int n, on1, on2, on3, on4, on5;
    printf("Enter a number between 0 and 32767:");
    scanf("%d", &n);
    on1 = n % 8;
    on2 = (n / 8) % 8;
    on3 = ((n / 8) / 8) % 8;
    on4 = (((n / 8) / 8) / 8) % 8;
    on5 = ((((n / 8) / 8) / 8) / 8) % 8;
    printf("In octal, your number is:%01d%01d%01d%01d%01d", on5, on4, on3, on2, on1);
    return 0;
}