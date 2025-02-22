#include<stdio.h>
int main (void){
    int n, i = 2, i2 = 4;
    printf("Enter a number: \n");
    scanf("%d", &n);
    while(i2 <= n){
        printf("%d", i2);
        i += 2;
        i2 = i * i;
        if (i2 <= n){
            printf("\n");
        }
    }
return 0;
}