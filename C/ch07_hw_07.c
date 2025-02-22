#include <stdio.h>
int main (void){
    char w;
    float i = 0.0, j = 0.0;
    printf("Enter a sentence: \n");
    while((w = getchar()) != '\n'){
        if(w != ' ' && w != '\t'){
            j++;
        }
        else if(w == ' ' || w == '\t'){
            i++;
        }
    }
    printf("Characters: %.0f\n", j);
    printf("Words: %.0f\n", i+1);
    printf("Average word length: %.1f", j / (i + 1));
    
    return 0;
}