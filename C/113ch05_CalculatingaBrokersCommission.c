#include <stdio.h>
int main (void){
    int tradeValue=0;
    float commission=0.0;
    printf("Enter value of trade: ");
    scanf("%d", &tradeValue);
    if(tradeValue > 500000){
        commission = 255 +0.0009f * tradeValue;
    }
    else if (tradeValue > 50000 &&tradeValue <= 500000){
        commission = 155 +0.0011f * tradeValue;
    }
    else if (tradeValue > 20000 &&tradeValue <= 50000){
        commission = 100 +0.0022f * tradeValue;
    }
    else if (tradeValue > 6250 &&tradeValue <= 20000){
        commission = 76 +0.0034f * tradeValue;
    }
    else if (tradeValue > 2500 &&tradeValue <= 6250){
        commission = 56 +0.0066f * tradeValue;
    }
    else{
        commission = 30 +0.017f * tradeValue;
    }
    if (commission <39){
        commission = 39.00;
    }
    printf("Commission: $%.2f", commission);
    return 0;
}