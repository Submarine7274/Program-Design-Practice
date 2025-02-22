/*編寫一個程式，實現以下功能：

1. 定義一個遞迴函數 reverseString(char str[], int start, int end)，反轉字串內容。
2. 輸入的字串為 str，起始索引為 start，結束索引為 end。
3. 主程式讀取一個字串，並呼叫遞迴函數反轉後輸出結果。

範例Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
Hello
-------------------------- 
Output： 
-------- 
olleH
--------------------------*/
#include<stdio.h>
#include<string.h>
void reverseString(char str[], int start, int end);
int main (void){
    char string[100];
    fgets(string, sizeof(string),stdin);
    if(string[strlen(string)-1] =='\n'){
        string[strlen(string)-1] ='\0';
    }
    reverseString(string, 0, strlen(string)-1);
    printf("%s", string);
    return 0;
}
void reverseString(char str[], int start, int end){
    if(start >end){
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start+1,end-1);
}