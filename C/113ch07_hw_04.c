#include <stdio.h>
#include <ctype.h>
int main (void){
    char sentence[1000];
    int vowels = 0;
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    for(int i = 0; sentence[i]; i++){
        sentence[i] = tolower(sentence[i]);
        switch(sentence[i]){
            case 'a': case 'e': case 'i': case 'o': case 'u':
            vowels ++;
            break;
        }
    }
    if(vowels > 1){
        printf("Your sentence contains %d vowels.", vowels);
    }
    else{
        printf("Your sentence contains %d vowel.", vowels);
    }
    return 0;
}

/*另解
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
*/