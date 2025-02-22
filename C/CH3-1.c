#include <stdio.h>
int main (void)
{
    int X = 40;
    float y = 839.21f;
printf("|%d|%5d|%-5d|%5.3d|\n", X, X, X, X);
printf("|%10.3f|%10.3e|%-10g|", y, y, y, y);
return 0;
}