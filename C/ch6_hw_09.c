#include<stdio.h>

int main (void) {
    int n, ns = 1;
    float e = 1.0;
    scanf("%d", &n);
    if(n >=1 && n <= 7){
    for (int i = 1; i <= n; ++i) {
        ns *= i;
        e += 1.0 / ns;
    }
    }
    else {NULL;}
    printf("%.4f", e);
    return 0;
}