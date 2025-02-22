#include<stdio.h>
int main (void){
    int n=0, i =1, r=0;
    scanf("%d", &n);
    while(i<=n){
        r += i;
        i++;
        //printf("%d\n", r);
    }
    printf("%d", r);
    return 0;
}