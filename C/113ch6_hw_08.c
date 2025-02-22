#include<stdio.h>
int main (void){
    int n = 0, sdotw = 0;
    scanf("%d", &n);
    scanf("%d", &sdotw);
    for (int i = 1; i < sdotw; i++){
        printf("   ");
    }
    for(int i = 1; i<=n; i++){
        printf("%2d ", i);
        if(((sdotw + i -1) %7) == 0){
            printf("\n");
        }
    }
    return 0;
}