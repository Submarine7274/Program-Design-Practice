#include <stdio.h>
int main (void){
    int n, s = 0;
    while(1){
     scanf("%d", &n);
    if(n < 0 ){
        continue;
    }
    else if(n > 0){
        s += n;
    }
    else if (n == 0){
        break;
    }
    }
    printf("%d", s);
    return 0;
}