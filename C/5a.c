/*Write a function named capitalize that capitalizes all letters in its argument. 
The argument will be a null-terminated string containing arbitrary characters. not just letters. 
Use array subscripting to access the characters in the string. 
Hint: Use the toupper function to convert each character to upper-case.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void capitalize( char[]);
int main (void){
    char input[100];
    fgets(input,sizeof(input),stdin);
    capitalize(input);
    printf("%s", input);
    return 0;
}
void capitalize(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]); 
    }
}