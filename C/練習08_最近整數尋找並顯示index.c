/*編寫一個程式，實現以下功能：
1. 輸入10個整數，指派至myArray陣列中。
2. 輸入1個整數myInt
3. 在myArray中尋找小於等於myInt且最大的整數，再輸出一個空格後，再輸出該整數在myArray中相對應的index。(index從0開始)
4. 若myArray中所有整數皆超過myInt，則輸出大寫”NO”。

範例Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
2 3 5 7 11 13 17 19 23 29
20
-------------------------- 
Output： 
-------- 
19 7
--------------------------*/
#include<stdio.h>
void findLessorEqualmyInt(int array[], int number);
int main (void){
    int myArray[10], myInt =0;
    for(int i =0; i<10; i++){
        scanf("%d", &myArray[i]);
    }
    scanf("%d", &myInt);
    findLessorEqualmyInt(myArray, myInt);
    return 0;
}
void findLessorEqualmyInt(int array[], int number){
    int max = -1; 
    int index = -1; 
    for (int i = 0; i < 10; i++) {
        if (array[i] <= number && array[i] > max) {
            max = array[i];
            index = i;
        }
    }

    if (index == -1) {
        printf("NO\n");
    } else {
        printf("%d %d\n", max, index);
    }
}