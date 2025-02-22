#include<stdio.h>
void de(int i);
int main (void){
    int i;
    scanf("%d", &i);
    de(i);
    return 0;
}
void de(int i){
    for(;i >= 0; i--){
        printf("%d\n", i);
    }
}