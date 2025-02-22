#include <stdio.h>
#include <ctype.h>
int main (void){
    char firstName[100], lastName[100], initial;
    printf("Enter a first and last name: ");
    scanf("%s", firstName);
    scanf("%s", lastName);
    initial = toupper(firstName[0]);
    printf("%s, %c.", lastName, initial);
    return 0;
}