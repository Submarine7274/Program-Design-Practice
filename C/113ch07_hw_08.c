#include <stdio.h>
#include <math.h>
int main (void){
    double num = 0.0f, guess = 1.0f, new_guess = 0.0f;
    printf("Enter a positive number: ");
    scanf("%lf", &num);
    do{
        new_guess = (guess + (num/guess)) /2;
        if(fabs(new_guess -guess)< 0.0001 *guess){
            break;
        }
        guess = new_guess;
    }while(1);
    
    printf("Square root: %.5f", new_guess);
    return 0;
}