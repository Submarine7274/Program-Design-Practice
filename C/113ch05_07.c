#include <stdio.h>
int main (void){
    float pps=0.0, obcommission=0.0, value=0.0, rbcommission=0.0, share=0;
    printf("Enter the number of shares: ");
    scanf("%f", &share);
    printf("Enter price per share: ");
    scanf("%f", &pps);
    value = share * pps;
    if (share < 2000){
        rbcommission = 33 + 0.03 * share;
    }
    else{
        rbcommission = 33 + 0.02 * share;
    }
    if(value > 500000){
        obcommission = 255 +0.0009f * value;
    }
    else if (value > 50000 &&value <= 500000){
        obcommission = 155 +0.0011f * value;
    }
    else if (value > 20000 &&value <= 50000){
        obcommission = 100 +0.0022f * value;
    }
    else if (value > 6250 &&value <= 20000){
        obcommission = 76 +0.0034f * value;
    }
    else if (value > 2500 &&value <= 6250){
        obcommission = 56 +0.0066f * value;
    }
    else{
        obcommission = 30 +0.017f * value;
    }
    if (obcommission <39){
        obcommission = 39.00;
    }
    printf("Original broker's commission: $%.2f\n",obcommission);
    printf("Rival broker's commission: $%.2f", rbcommission);
    return 0;
}