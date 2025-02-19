#include <stdio.h>
#include <math.h>
#define BASE 100.00f
int main (void){
    double rate;
    int years;
    printf("Enter interest rate: ");
    scanf("%lf" ,&rate);
    printf("Enter number of years: ");
    scanf("%d", years);
    printf("\nYears");
    for(int i =0; i<5; i++){
        printf("%6.0f%%", rate +i); //%%是為了輸出%符號
    }
    printf("\n");
    for(int i = 1; i<= years; i++){
        printf("%3d    ",i);

        for (int j = 0; j < 5;j ++){
            double currentRate = rate +i;
            double number = BASE * pow(1 +(currentRate/100), i);
            printf("%7.2f", number);
        }
        printf("\n");
    }
    return 0;
}