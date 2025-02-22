#include <stdio.h>
int count (int);
int twenty, ten, five, one;
int main (void){
    int dollar;
    scanf("%d", &dollar);
    count(dollar);
    printf("%d %d %d %d", twenty, ten, five, one);
    return 0;
}

int count(int dollar){
    twenty = dollar / 20;
    ten = (dollar % 20) / 10;
    five = (dollar % 20 % 10) / 5;
    one = (dollar %20 % 10 % 5);
    return 0;
}