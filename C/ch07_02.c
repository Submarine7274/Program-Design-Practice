#include <stdio.h>
int main (void){
    int l = 0 ,n;
    printf("Enter a message:");
    while((n = getchar()) != '\n'){
        l++;
    }
    printf("Your message was %ld character(s) long.", l);
    return 0;
}