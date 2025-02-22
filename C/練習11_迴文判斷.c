/*編寫一個語言程式，實現以下功能：

1. 定義一個函數 isPalindrome，用於檢測一個字串是否為迴文，並在主程式中呼叫該函數判斷是否為迴文。
2. 如果是迴文，輸出大寫 "YES"；否則輸出大寫 "NO"。

限制:

1. 字串長度不超過 100 個字符。
2. 忽略大小寫，並排除非字母字符進行檢測。

範例Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
A man, a plan, a canal, Panama
-------------------------- 
Output： 
-------- 
YES
--------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
bool isPalindrome(const char string[]);
int main (void){
    char string[100];
    fgets(string,sizeof(string), stdin);
    if(isPalindrome(string)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
bool isPalindrome(const char string[]){
    char filtered[100];
    int length = 0;
    for(int i =0; string[i]!='\0';i++){
        if (isalpha(string[i])) {
            filtered[length++] = tolower(string[i]);
        }
    }
    filtered[length] ='\0';
    for(int i =0, j = length-1;i <j;i++, j--){
        if (filtered[i] != filtered[j]) {
            return false;
        }
    }
    return true;
}
