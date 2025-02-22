#include <stdio.h>
int main (void){
    char ch;
    int count = 0;
    printf("Enter a message:");
    while((ch = getchar()) != '\n'){
        count++;
    }
    printf("Your message was %d character(s) long.", count);
    return 0;
}