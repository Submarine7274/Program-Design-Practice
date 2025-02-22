#include<stdio.h>
int main (void){
    int a,n, mn = 0, max = 100;
    printf("Enter the answer number(0-100): \n");
    scanf("%d", &a);
    printf("Game start!\n");
    printf("\n");
    mn = 0;
    max = 100;
    while(n != a){
        if (n < a && mn < n ){
            mn = n;
        }
        else if(n > a && max > n){
            max = n;
        }
        printf("Enter a number(%d-%d):\n",mn ,max);
        scanf("%d", &n);
    }
    if (n == a){
        printf("BANG!");
    }
    return 0;
}