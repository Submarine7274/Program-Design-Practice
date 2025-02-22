#include<stdio.h>
int main (void){
    int sum = 0, num = 0;
    printf("Enter a nonnegative integer: ");
    scanf("%d", &num);
    do{
        sum +=num%10;
        num /=10;
        //printf("%d\n", sum);
    }while(num >0);
    printf("%d", sum);
    return 0;
}