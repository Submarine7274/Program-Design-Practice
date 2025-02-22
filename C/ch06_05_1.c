#include<stdio.h>
int main (void){
    int n, n2;
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        n2 = i *i;
        printf("%10d%10d\n",i , n2);
    }
return 0;
}