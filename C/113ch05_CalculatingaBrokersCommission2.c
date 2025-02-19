#include <stdio.h>
int main (void){
    int tradeValue=0;
    float commission=0.0;
    printf("Enter value of trade: ");
    scanf("%d", &tradeValue);
    if(tradeValue >= 1000000){
        commission = 250 +0.0009f * tradeValue;
    }
    else if (tradeValue >= 55000 &&tradeValue < 1000000){
        commission = 200 +0.0015f * tradeValue;
    }
    else if (tradeValue >= 20000 &&tradeValue < 55000){
        commission = 180 +0.005f * tradeValue;
    }
    else if (tradeValue >= 6000 &&tradeValue < 20000){
        commission = 110 +0.01f * tradeValue;
    }
    else if (tradeValue >= 2000 &&tradeValue < 6000){
        commission = 80 +0.015f * tradeValue;
    }
    else {
        commission = 50 +0.02f * tradeValue;
    }

    if (commission <70){
        commission = 70.00;
    }
    printf("Commission: $%.2f", commission);
    return 0;
}