#include<stdio.h>
int main (void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if((a*a) == ((b*b) + (c*c))){
        printf("%d", a);
    }
    else if((b*b) == ((a*a) + (c*c))){
        printf("%d", b);
    }
    else if((c*c) == ((a*a) + (b*b))){
        printf("%d", c);
    }
    return 0;
}