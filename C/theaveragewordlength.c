#include <stdio.h>
int main (void){
    char ch;
    float words= 0, characters = 0;
    printf("Enter a sentence: ");
    while((ch = getchar())!= '\n'){
        if(ch != ' '&& ch != '\t'){
            characters++;
        }
        else if(ch == ' '|| ch == '\t'){
            words++;
        }
    }
    printf("Characters: %f", characters);
    printf("Words: %f", words +1);
    printf("Average word length: %.1f", characters / (words +1));
    return 0;
}