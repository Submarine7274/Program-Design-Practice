#include<stdio.h>
int main (void){
    printf("Enter integers (0 to terminate): ");
    int n = 1, sum = 0;
    while(n != 0){
        scanf("%d", &n);
        sum += n;
        //printf("%d\n", sum);
    }
    printf("The sum is: %d", sum);
    return 0;
}