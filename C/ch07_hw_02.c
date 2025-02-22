#include<stdio.h>
#include <ctype.h>
int main (void){
    int s = 0;
    char c;
    printf("Enter a word: ");
     while ((c = getchar()) != '\n') {
        c = toupper(c); 

        if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U') {
            s += 1;
        } else if (c == 'D' || c == 'G') {
            s += 2;
        } else if (c == 'B' || c == 'C' || c == 'M' || c == 'P') {
            s += 3;
        } else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y') {
            s += 4;
        } else if (c == 'K') {
            s += 5;
        } else if (c == 'J' || c == 'X') {
            s += 8;
        } else if (c == 'Q' || c == 'Z') {
            s += 10;
        }
    }
    printf("Scrabble value: %d", s);
    return 0;
}