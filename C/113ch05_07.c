#include <stdio.h>
int main (void){
    float pricePerShare=0.0, originalBrokersCommission=0.0, value=0.0, rivalBrokersCommission=0.0, share=0;     //宣告浮點數的變數
    printf("Enter the number of shares: ");     //輸出提示
    scanf("%f", &share);    //輸入股數
    printf("Enter price per share: ");   //輸出提示
    scanf("%f", &pricePerShare);    //輸入每股價格
    value = share * pricePerShare;  //計算股票總價
    if (share < 2000){  //計算競爭對手的手續費
        rivalBrokersCommission = 33 + 0.03 * share;
    }
    else{
        rivalBrokersCommission = 33 + 0.02 * share;
    }
    if(value > 500000){ //計算原本的手續費
        originalBrokersCommission = 255 +0.0009f * value;
    }
    else if (value > 50000 &&value <= 500000){
        originalBrokersCommission = 155 +0.0011f * value;
    }
    else if (value > 20000 &&value <= 50000){
        originalBrokersCommission = 100 +0.0022f * value;
    }
    else if (value > 6250 &&value <= 20000){
        originalBrokersCommission = 76 +0.0034f * value;
    }
    else if (value > 2500 &&value <= 6250){
        originalBrokersCommission = 56 +0.0066f * value;
    }
    else{
        originalBrokersCommission = 30 +0.017f * value;
    }
    if (originalBrokersCommission <39){
        originalBrokersCommission = 39.00;
    }
    printf("Original broker's commission: $%.2f\n",originalBrokersCommission);  //輸出結果
    printf("Rival broker's commission: $%.2f", rivalBrokersCommission);
    return 0;
}