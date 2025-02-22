#include <stdio.h>
int main (void){
    long num = 0, sum = 0;
    scanf("%ld", &num);
    while(num != 0){
        sum += num;
        scanf("%ld", &num);
    }
    printf("%ld", sum);
    return 0;
}