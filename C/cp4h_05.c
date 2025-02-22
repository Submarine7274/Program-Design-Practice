#include<stdio.h>
int main(void)
{
    int f1, f2, f3, f4 ,f5 , f6, s1, s2, s3, s4, s5, cd;
    printf("Enter the first 11 digits of a UPC:");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &f1, &s1, &f2, &s2, &f3, &s3, &f4, &s4, &f5, &s5, &f6);
    cd = 9 - (((3 * (f1 + f2 + f3 + f4 + f5 + f6))+(s1 + s2 + s3 + s4 + s5) - 1) % 10);
    printf("Check digit:%d", cd);
    return 0;
}