/*1b
Write a program that finds the "smallest" and “largest” in a series of words. After the user
enters the words, the program will determine which words would come first and last if the
words were listed in dictionary order. The program must stop accepting input when the user
enters a four-letter word. Assume that no word is more than 20 letters long. An interactive
session with the program might look like this:
Enter word: Q93
Enter word: zebra
Enter word: rabbit
Enter word: catfish
Enter word: walrus
Enter word: cat
Enter word: fish
Smallest word: oat
Largest word: zebra
Hint: Use two strings named smal1esl:_worr:1 and largest_word to keep track of the
"srna1lest” and ‘‘largest‘’ words entered so far. Each time the user enters a new word. use
stromp to compare it with smallest_word'. if the new word is “smaller," use stropy
to save it in smallest_worr:1. Do a similar comparison with largest_worc1. Use
strlen to determine when the user has entered a four-letter word.
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main (void){
    char input[20], small[20], large[20];
    while (1){
        printf("Enter word: ");
        fgets(input, sizeof(input), stdin);
        size_t len = strlen(input);
        if(input[len -1] =='\n'){
            input[len -1] = '\0';
        }
        if(strlen(input) ==4){
            break;
        }
        if (strcmp(small, "") == 0 || strcmp(input, small) < 0) {
            strcpy(small, input);
        }
        if (strcmp(large, "") == 0 || strcmp(input, large) > 0) {
            strcpy(large, input);
        }
        
    }
    printf("Smallest word: %s\n", small);
    printf("Largest word: %s", large);
    return 0;
}