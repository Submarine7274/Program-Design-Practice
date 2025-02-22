/*編寫一個程式，實現以下功能：

1. 定義一個遞迴函數 fibonacci(n)，計算並返回費式數列的第n項。
費式數列的定義為：
F(0)=0
F(1)=1
F(n)=F(n-1)+F(n-2) （當n-2>=0）
2. 主程式中讀取一個整數 n，並呼叫遞迴函數輸出結果。

範例Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
7
-------------------------- 
Output： 
-------- 
13
--------------------------*/
#include <stdio.h>
int fibonacci(int n);
int main (void){
    int n=0;
    scanf("%d", &n);
    printf("%d",fibonacci(n));
    return 0;
}
int fibonacci(int n){
    if(n ==0){
        return 0;
    }
    else if(n ==1){
        return 1;
    }
    else{
        return fibonacci(n-1) +fibonacci(n-2);
    }
}