#include <stdio.h>
int main (void){
    int m=0, n =0;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    while(n !=0){
        int remainder = m %n;
        m = n;
        n = remainder;
    }
    printf("Greatest common divisor: %d", m);
    return 0; 
}