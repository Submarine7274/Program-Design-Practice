#include <stdio.h>
int main(void){
    int i, n, i2;
    scanf("%d", &n);
    for(i = 2; (i2 = i * i) <= n; i += 2){
        printf("%d\n", i2);
    }
    return 0;
}