#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main (void){
    char mes[1000];
    fgets(mes, sizeof(mes), stdin);
    for(int i = 0; mes[i] !='\0'; i++){
        printf("%c", toupper(mes[i]));
    }
    //printf("\n");
    for(int i = 0; mes[i] !='\0'; i++){
        printf("%c", tolower(mes[i]));
    }
    return 0;
}