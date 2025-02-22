#include <stdio.h>
int main (void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, cd;
    printf("Enter the first 12 digits of an EAN:");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);
    cd = 9 - ((((3 * (n2 + n4 + n6 + n8 + n10 + n12)) + (n1 + n3 + n5 + n7 + n9 + n11)) - 1) % 10);
    printf("Check digit:%d", cd);
    return 0;
}