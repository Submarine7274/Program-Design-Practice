#include <stdio.h>
    int main (void){
        int a = 36;
        int b = 0x24;
        int c = 044;
        int d = 0b00100100;
        if(a == b && a == c && a == d){
            printf("a = b = c = d");
        }
        else{
            printf("They are not the same!");
        }
        return 0;
    }