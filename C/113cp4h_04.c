#include <stdio.h>
int main (void){
    int num=0, d[5]={0};
    printf("Enter a number between 0 and 32767:");
    scanf("%d", &num);
    //printf("In octal, your number is:%05O", num);
    for (int i = 0; i<= 4; i++){
        d[i]= num % 8;
        num /=8;
    }
    printf("In octal, your number is:%01d%01d%01d%01d%01d",d[4], d[3], d[2], d[1], d[0]);
    return 0;
}