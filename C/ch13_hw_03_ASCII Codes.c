#include<stdio.h>
int main (void){
    int code = 0;
    char c;
    while(code != -1){
        scanf("%d", &code);
        if(code  == -1){
            break;
        }
        c = code;
        printf("%c\n", c);
    }
    return 0;
}