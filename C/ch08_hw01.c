#include<stdio.h>
#include<ctype.h>
#include<string.h>

void biff(char mes[]){
    int i = 0;
    while(mes[i] != '\0'){
        char c = toupper(mes[i]);
        switch(c){
            case 'A':
            printf("4");
            break;
            case 'B':
            printf("8");
            break;
            case 'E':
            printf("3");
            break;
            case 'I':
            printf("1");
            break;
            case 'O':
            printf("0");
            break;
            case 'S':
            printf("5");
            break;
            default:
            printf("%c", c);
        }
    i++;
    }
    
}

int main(void){
    char mes[100];
    printf("Enter message: \n");
    fgets(mes, sizeof(mes), stdin);
    if (mes[strlen(mes) - 1] == '\n') {
        mes[strlen(mes) - 1] = '\0';
    }
    printf("In B1FF-speak: ");
    biff(mes);
    puts("!!!!!!!!!!");
    return 0;
}