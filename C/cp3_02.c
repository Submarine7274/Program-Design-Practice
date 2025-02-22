#include <stdio.h>
int main (void)
{
    int n1, n2, d1, d2, re, red;
    printf("Enter first fraction:");
    scanf("%d/%d", &n1, &d1);
    printf("Enter second fraction:");
    scanf("%d/%d", &n2, &d2);
    re = (n1 * d2 + n2 * d1) ;
    red = (d1*d2);
    printf("The sum is ");
    printf("%d/%d", re, red);
    return 0;
}