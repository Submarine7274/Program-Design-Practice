#include <stdio.h>
#include <ctype.h>

int main(void) {
    int t = 0;
    char s;

    printf("Enter a sentence: \n");
    
    while ((s = getchar()) != '\n') {
        s = toupper(s);

        if (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') {
            t++;
        }
    }

    printf("Your sentence contains %d vowels.", t);

    return 0;
}