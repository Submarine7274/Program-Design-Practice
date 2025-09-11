#include<stdio.h>
int main (void){
    int speed; //宣告風速變數
    printf("Enter wind speed (knots): ");   //提示輸入風速
    scanf("%d", &speed);    //讀取風速
    if(speed < 1){  //根據風速範圍判斷風力等級
        printf("Wind force at %d knots is Calm", speed);    //輸出風力等級 如果風速小於1節 則為無風
    }
    else if(speed >= 1 && speed <= 3 ){
        printf("Wind force at %d knots is Light air", speed);       //如果風速在1到3節之間 則為輕風
    }
    else if(speed >= 4 && speed <= 27 ){
        printf("Wind force at %d knots is Breeze", speed);  //如果風速在4到27節之間 則為微風
    }
    else if(speed >= 28 && speed <= 47 ){
        printf("Wind force at %d knots is Gale", speed);    //如果風速在28到47節之間 則為大風
    }
    else if(speed >= 48 && speed <= 63 ){
        printf("Wind force at %d knots is Storm", speed);   //如果風速在48到63節之間 則為暴風
    }
    else if(speed > 63 ){
        printf("Wind force at %d knots is Hurricane", speed);   //如果風速大於63節 則為颶風
    }
    return 0;
}