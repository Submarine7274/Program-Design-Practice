#include<stdio.h>
int main (void){
    int answer=0, guess=-1, upper = 100, lower = 0;
    printf("Enter the answer number(0-100):\n");
    scanf("%d", &answer);
    printf("Game start!\n\n");
    for(;guess != answer;){
        printf("Enter a number(%d-%d): \n", lower, upper);
        scanf("%d", &guess);
        if(guess > answer){
            upper = guess;
        }
        else if(guess <answer){
            lower = guess;
        }
        else{
            printf("BANG!");
        }
    }
    return 0;
}