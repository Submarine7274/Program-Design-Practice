#include<stdio.h>
int main(void){
    int snumber = 0, guess=-1;
    printf("Enter a secret number 1~100");
    scanf("%d", &snumber);
    while(guess != snumber){
        scanf("%d", &guess);
        if(guess >1000||guess <1){
            printf("x\n");
        }
        else if(guess > snumber){
            printf("Too-high\n");
        }
        else if(guess < snumber){
            printf("Too-low\n");
        }
        else if(guess == snumber){
            printf("Success\n");
        }
    }
    return 0;
}