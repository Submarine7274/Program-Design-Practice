#include<stdio.h>

void laggest (int a, int b);

int main(void){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    laggest(a, b);
    return 0;
}

void laggest(int a, int b){
    int l = (a > b)? a : b;
    printf("%d", l);
}