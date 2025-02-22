#include <stdio.h>
int main (void){
    int n1, n2, n3;
    scanf("(%2d) %4d-%4d", &n1, &n2, &n3);
    printf("You entered %02d.%4d.%4d", n1, n2, n3);
    return 0;
}