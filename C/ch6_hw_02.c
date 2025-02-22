#include<stdio.h>
int main (void){
    int m , n, gcd, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    if (m == 0){
        gcd = n;
    }
    else if(n == 0){
        gcd = m;
    }
    else if (n > m){
        temp = n;
        n = m;
        m = temp;
    }
    while(n != 0){
       temp = n;
       n = m % n;
       m = temp;
    }
    gcd = m;
    printf("Greatest common divisor: %d", gcd);
    return 0;
}