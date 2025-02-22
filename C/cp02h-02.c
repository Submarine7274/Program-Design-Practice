#include<stdio.h>
int main (void){
    float dollar, taxed;
    scanf("%f", &dollar);
    taxed = dollar *1.05f;
    printf("%.2f", taxed);
    return 0;
}