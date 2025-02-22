#include<stdio.h>
#include<ctype.h>
int main(void){
    char f[20];
    char l[20];
    char i;
    printf("Enter a first and last name: \n");
    scanf("%s", f);
    scanf("%s", l);
    while(getchar() != '\n');
    i = toupper (f[0]);
    printf("%s, %c.", l ,i);
    return 0;
}