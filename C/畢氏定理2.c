#include <stdio.h>
int main (void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == 0 || b == 0 || c == 0){
        printf("0");
    }
    else if ((a * a) == ((b * b) + (c * c))){
        printf("%d", a);
    }
    else if((b * b) == ((a * a) + (c * c))){
        printf("%d", b);
    }
    else if((c * c) == ((a * a) + (b * b))){
        printf("%d", c);
    }
    else {printf("0");}
    return 0;
}