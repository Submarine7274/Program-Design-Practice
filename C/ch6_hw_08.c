#include<stdio.h>
int main (void){
    int dd, d, s, i;
    scanf("%d", &dd);
    scanf("%d", &s);
    for (i = 1; i < s; i++){
        printf("   ");
    }

    for (d = 1; d <= dd; d++){
        printf("%3d", d);
        if ((d + s - 1 ) % 7 == 0 || d == dd ) {
            printf("\n");
        }
    }
return 0;
}