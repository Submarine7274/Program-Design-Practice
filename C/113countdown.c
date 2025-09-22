#include <stdio.h>
void countdown(int inputNumber); //函式宣告 保持先宣告函式原型的好習慣
int main (void){
    int number; //宣告變數 number是輸入的數字
    scanf("%d", &number);   //讀取輸入的數字
    countdown(number);  //呼叫函式並傳入參數
    return 0;
}
void countdown(int inputNumber){
    for(int i = inputNumber ; i>=0; i--){   //從輸入的數字開始倒數到0
        printf("%d\n", i);  //輸出目前的數字
    }
}