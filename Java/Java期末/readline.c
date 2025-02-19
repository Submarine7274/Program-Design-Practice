#include <stdio.h>
#include <string.h>
#include <ctype.h>
int readline(char [],int );
int readline(char str[],int n){
    int i=0,c;
    while(isspace(c = getchar())){
        ;                           //忽略空白
    }
    for(; c!= '\n'&&c != EOF; c= getchar()){
        if(i <n-1){
            str[i++] = c;
        }
    }
    str[i] = '\0';
    return i;
}