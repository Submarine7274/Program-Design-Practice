#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main (void){
    char input[100];
    int length =0;
    fgets(input, sizeof(input), stdin);
    length = strlen(input);
    if(input[length-1] == '\n'){
        input[length-1]='\0';
    }
    for(int i = length-1; i>=0; i--){
        printf("%c", input[i]);
    }
    return 0;
}