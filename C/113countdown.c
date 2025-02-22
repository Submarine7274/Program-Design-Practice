#include <stdio.h>
void countdown(int n);
int main (void){
    int n;
    scanf("%d", &n);
    countdown(n);
    return 0;
}
void countdown(int n){
    for(int i = n ; i>=0; i--){
        printf("%d\n", i);
    }
}