#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main (void){
    char line[100];
    int length = 0;
    fgets(line, sizeof(line), stdin);
    length = strlen(line);
    if(line[length-1] =='\n'){
        line[length-1] ='\0';
        length--;
    }
    for(int i = length -1; i>=0; i--){
        printf("%c", line[i]);
    }
    return 0;
}