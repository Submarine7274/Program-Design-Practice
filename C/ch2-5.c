#include <stdio.h>
int main (void) 
{
    float l, ir, lir, mp, p1, p2, p3;
    scanf("%f", &l);
    scanf("%f", &ir);
    scanf("%f", &mp);
    lir = ir / 12 /100 +1;
    p1 = l * lir - mp;
    p2 = p1 * lir - mp;
    p3 = p2 * lir - mp;
    printf("$%.2f\n$%.2f\n$%.2f", p1, p2, p3);
    return 0;
}