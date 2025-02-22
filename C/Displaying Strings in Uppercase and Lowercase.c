#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void){
    char input[100];
    fgets(input, sizeof(input),stdin);
    for(int i =0; i<strlen(input); i++){
        printf("%c", tolower(input[i]));
    }
    for(int i =0; i<strlen(input); i++){
        printf("%c", toupper(input[i]));
    }
    return 0;
}