#include <stdio.h>
int main (void){
    int n1, n2, n3, n4, d1, d2, d3, d4;
    scanf("%d/%d", &n1, &d1);
    scanf("%d/%d", &n2, &d2);
    scanf("%d/%d", &n3, &d3);
    n4 = n1 * d2 * d3 + n2 * d1 * d3 + n3 * d1 *d2;
    d4 = d1 * d2 * d3;
    printf("%d/%d", n4, d4);
    return 0;
}