#include<stdio.h>
int main (void){
    int n, sn = 0, d;
    printf("Enter a nonnegative integer: ");
    scanf("%d", &n);
    while(n > 0){
        d = n % 10;
        sn += d;
        n /= 10;
    }
    printf("%d", sn + n);
    return 0;
}