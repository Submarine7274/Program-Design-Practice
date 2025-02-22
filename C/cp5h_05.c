#include<stdio.h>
int main (void)
{
    float tx, ic;
    printf("Enter amount of taxable income: ");
    scanf("%f", &ic);
    if(ic < 750){
        tx = ic * 0.01;
    }
    else if (ic < 2250){
        tx = 7.5f + (ic - 750) * 0.02;
    }
    else if (ic < 3750){
        tx = 37.5 + (ic - 2250) * 0.03;
    }
    else if (ic < 5250){
        tx = 82.5 + (ic - 3750) * 0.04;
    }
    else if (ic <= 7000){
        tx = 142.5 + (ic - 5250) * 0.05;
    }
    else{
        tx = 230 + (ic - 7000) * 0.06;
    }
printf("Tax due is: $%.2f",tx);
return 0;
}