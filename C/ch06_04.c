#include<stdio.h>
int main (void){
    int n, d = 1;
    printf("Enter a nonnegative integer: ");
    scanf("%d", &n);
    while((n / 10) > 0){
        n = n / 10;
        d++;
    }
    printf("The number has %d digit(s).", d);
    return 0;
}