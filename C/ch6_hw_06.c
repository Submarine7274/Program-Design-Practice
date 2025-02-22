#include <stdio.h>
int main (void){
    int m, n, gcd, temp, tempu, tempd;
    printf("Enter a fraction (x/y): \n");
    scanf("%d/%d", &m ,&n);
    tempu = m;
    tempd = n;
    if(m == 0){
        gcd = n;
    }
    else if (n == 0){
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
    tempu /= m;
    tempd /= m;
    printf("GCD = %d\n", gcd);
    printf("In lowest terms: %d/%d", tempu, tempd);
}