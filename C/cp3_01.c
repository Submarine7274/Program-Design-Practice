#include <stdio.h>
int main (void)
{
    int i;
    float f;
    scanf("%d %f", &i, &f);
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|", f, f, f);
    return 0;
}