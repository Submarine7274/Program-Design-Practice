#include<stdio.h>
int main (void){
    int d = 0, n;
    printf("Enter  a nonnegative integer: ");
    scanf("%d", &n);
    do
    {
        n /= 10;
        d++;
    }while(n >0);
    printf("The number has %d digit(s).\n", d);
    return 0;
}