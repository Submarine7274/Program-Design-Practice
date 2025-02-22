#include <stdio.h>
int function (int);
int main (void){
    int x;
    scanf("%d", &x);
    x = function(x);
    printf("%d", x);
    return 0;
}

int function(int x){
    x = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6;
    return x;
}