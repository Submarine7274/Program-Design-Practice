#include <stdio.h>
int main (void)
{
    int d1, d2, d3, d4, reu, red;
    scanf("%d/%d", &d1, &d2);
    scanf("%d/%d", &d3, &d4);
    reu = (d1 * d3);
    red = (d2 * d4);
    printf("%d/%d", reu ,red);
    return 0;
}