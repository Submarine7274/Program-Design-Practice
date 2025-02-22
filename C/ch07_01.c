#include <stdio.h>
int main (void){
    long sum = 0, n = 0;
    scanf("%ld", &n);
    while(n != 0){
        sum += n;
        scanf("%ld", &n);
    }
    printf("%ld", sum);
    return 0;
}