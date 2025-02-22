#include <stdio.h>
int main (void){
    int n1, n2, n3, d1, d2, d3;
    printf("Enter first fraction:");
    scanf("%d/%d", &n1, &d1);
    printf("Enter second fraction:");
    scanf("%d/%d", &n2, &d2);
    n3 = n1 * d2 + n2 * d1;
    d3 = d1 * d2;
    printf("The sum is %d/%d", n3, d3);
    return 0;
}