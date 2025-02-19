#include <stdio.h>
int main (void){
    const char* vol[]={"Apple", "Banana", "Cherry", "Durian", "Egg", "Fish"};
    char ch;
    scanf("%c", &ch);
    switch(ch){
        case 'A':
        case 'a':
        printf("%s", vol[0]);
        break;
        case 'B':
        case 'b':
        printf("%s", vol[1]);
        break;
        case 'C':
        case 'c':
        printf("%s", vol[2]);
        break;
        case 'D':
        case 'd':
        printf("%s", vol[3]);
        break;
        case 'E':
        case 'e':
        printf("%s", vol[4]);
        break;
        case 'F':
        case 'f':
        printf("%s", vol[5]);
        break;
        default :
        printf("Error");
        break;
    }
    return 0;
}