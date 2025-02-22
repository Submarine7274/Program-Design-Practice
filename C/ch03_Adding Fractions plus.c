#include<stdio.h>
int main (void)
{
    int d1, d2, d3, b1, b2, b3, re1, re2;
    scanf("%d/%d", &d1, &b1);
    scanf("%d/%d", &d2, &b2);
    scanf("%d/%d", &d3, &b3);
    re1 = (d1 * b2 *b3) + (d2 * b1 * b3) + (d3 * b1 *b2);
    re2 = b1 * b2 * b3;
    printf("%d/%d", re1, re2);
    return 0;
}