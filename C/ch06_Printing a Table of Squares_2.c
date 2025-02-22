#include <stdio.h>
int main (void){
    int i = 1, n = 10, r=0;
    while(i <= n){
        r += i;
        i++;
        //printf("%d\n", r);
    }
    printf("%d", r);
    return 0;
}