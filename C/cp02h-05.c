#include <stdio.h>
float count(float, float, float);
int main (void){
    float loan, interest, payment;
    scanf("%f", &loan);
    scanf("%f", &interest);
    interest /= 1200;
    scanf("%f", &payment);
    for(int i = 0; i < 3; i++){
        loan = count (loan, interest, payment);
        if(i < 2){
        printf("$%.2f\n", loan);
        }
        else{
            printf("$%.2f", loan);
        }
    }
    return 0;
}
float count(float loan, float interest, float payment){
    loan = loan + (loan * interest) -payment;
    return loan;
}