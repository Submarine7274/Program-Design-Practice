#include<stdio.h>
int main (void){
    char ch;
    float words = 0.0f, charaters = 0.0f; 
    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n'){
        if(ch != ' ' &&ch  != '\t'){
            charaters++;
        }
        else if(ch == ' ' ||ch == '\t'){
            words++;
        }
    }
    printf("Characters: %.0f\n", charaters);
    printf("Words: %.0f\n", words+1);
    printf("Average word length: %.1f", charaters / (words+1));
}