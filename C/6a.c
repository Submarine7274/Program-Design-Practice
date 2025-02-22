
/*Write a function named censor that modifies a string by replacing every occurrence of foo by xxx. 
For example. the string " food fool" would become "xxxd xxxl ". 
Make the function as short as possible without sacrificing clarity. */
#include<stdio.h>
#include<ctype.h>
void censor(char[]);
int main (void){
    char input[100];
    fgets(input, sizeof(input), stdin);
    censor(input);
    return 0;
}
void censor(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if((str[i] =='f'||str[i] =='F')&&(str[i+1] == 'o'||str[i+1] == 'O')&&(str[i+2] == 'o'||str[i+2] =='O')){
            str[i]= 'x';
            str[i+1] = 'x';
            str[i+2] = 'x';
        }
    }
    printf("%s", str);
}