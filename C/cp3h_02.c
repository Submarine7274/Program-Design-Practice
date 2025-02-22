#include<stdio.h>
int main(void)
{
    int ln, F4, L4;
    scanf("(%2d)%4d-%4d", &ln, &F4, &L4);
    printf("You entered %02d.%4d.%4d", ln, F4, L4);
    return 0;
}