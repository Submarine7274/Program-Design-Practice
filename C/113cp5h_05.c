#include <stdio.h>
int main(void){
    float inCome =0.0, tax =0.0;
    printf("Enter amount of taxable income: ");
    scanf("%f", &inCome);
    if(inCome <0){
        printf("error");
    }
    else{
        if(inCome<=750){
            tax = inCome *0.01;
        }
        else if(inCome >= 751 && inCome <= 2250){
            tax = (inCome - 750) *0.02 +7.5;
        }
        else if(inCome >= 2251 && inCome <= 3750){
            tax = (inCome - 2250) *0.03 +37.5;
        }
        else if(inCome >= 3751 && inCome <= 5250){
            tax = (inCome - 3750) *0.04 +82.5;
        }
        else if(inCome >= 5251 && inCome <= 7000){
            tax = (inCome - 5250) *0.05 +142.5;
        }
        else{
            tax = (inCome - 7000) *0.06 +230;
        }
    }
    printf("Tax due is: $%.2f", tax);
    return 0;
}