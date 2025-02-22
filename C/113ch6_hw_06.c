#include <stdio.h>
int main (void){
    int m = 0, n = 0, gcd = 0, number1=0, number2=0;
    printf("Enter a fraction (x/y): ");
    scanf("%d/%d", &number1, &number2);
    m = number1;
    n = number2;
    while(n !=0){
        int remainder = m %n;
        m = n;
        n = remainder;
    }
    gcd = m;
    number1 /= gcd;
    number2 /= gcd;
    printf("GCD = %d\nIn lowest terms: %d/%d", gcd, number1, number2);
    return 0;
}