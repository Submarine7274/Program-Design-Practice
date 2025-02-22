#include<stdio.h>
int main (void){
    char c;
    scanf("%c", &c);
    if(c == 'a' || c == 'A'){
        printf("Apple");
    }
    else if(c == 'b' || c == 'B'){
        printf("Banana");
    }
    else if(c == 'c' || c == 'C'){
        printf("Cherry");
    }
    else if(c == 'd' || c == 'D'){
        printf("Durian");
    }
    else if(c == 'e' || c == 'E'){
        printf("Egg");
    }
    else if(c == 'f' || c == 'F'){
        printf("Fish");
    }
    else{printf("Error");}
    return 0;
}