#include <stdio.h>
int largest(int a, int b);
int main (void){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", largest(x, y));
    return 0;
}
int largest(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}