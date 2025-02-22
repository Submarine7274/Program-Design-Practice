#include<stdio.h>
int main (void){
    int n = 0, digit = 0;
    printf("Enter a nonnegative integer: ");
    scanf("%d", &n);
    do{
        n /=10;
        digit++;
    }while(n >0);
    printf("The number has %d digit(s).", digit);
    return 0;
}