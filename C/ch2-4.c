#include <stdio.h>
int main (void)
{
    int x, y, z, d20, d10, d5, d1;
    scanf("%d", &x);
    d20 = x / 20;
    y = x % 20;
    d10 = y / 10;
    z = y % 10;
    d5 = z / 5;
    d1 = z % 5;
    printf("%d %d %d %d", d20, d10, d5, d1);
return 0;
}