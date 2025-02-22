#include <stdio.h>
int main (void){
    int n=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i = 1; (2*i)*(2*i)<=n;i++){
        printf("%d", (2*i)*(2*i));
        if(i < n){
            printf("\n");
        }
    }
    return 0;
}