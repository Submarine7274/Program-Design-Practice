#include<stdio.h>
void encrypt(char* mes, int shift){
    while(*mes){
        if ('A' <= *mes && *mes <= 'Z'){
            *mes = ((*mes - 'A') + shift) % 26 + 'A';
        }
        else if ('a' <= *mes && *mes <= 'z'){
            *mes = ((*mes - 'a') + shift) % 26 + 'a';
        }
        mes++;
    }
}
int main(void){
    char mes[100];
    int shift;
    printf("Enter message to be encrypted: ");
    fgets(mes, sizeof(mes), stdin);
    if(mes[strlen(mes) - 1] == '\n'){
        mes[strlen(mes) - 1] = '\0';
    }
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    printf("Encrypted message: ");
    encrypt(mes, shift);
    printf("%s", mes);
    return 0;
}