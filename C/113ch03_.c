#include <stdio.h>
int main (void){
    int n1, n2, d1, d2, n3, d3;
    scanf("%d/%d", &n1, &d1);
    scanf("%d/%d", &n2, &d2);
    n3 = n1 *n2;
    d3 = d1 *d2;
    printf("%d/%d",n3, d3);
    return 0;
}