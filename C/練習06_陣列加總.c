/*編寫一個程式，實現以下功能：
1. 輸入10個整數，指派至myArray陣列中。
2. 計算myArray中這10個數字的總和並輸出。

範例Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
1 1 2 3 5 8 13 21 34 55
-------------------------- 
Output： 
-------- 
143
--------------------------*/
#include <stdio.h>
int main(void){
    int myArray[10], sum =0;
    for(int i =0; i<10; i++){
        scanf("%d", &myArray[i]);
    }
    for(int i =0; i <10; i++){
        sum += myArray[i];
    }
    printf("%d", sum);
    return 0;
}