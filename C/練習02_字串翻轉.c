/*編寫一個程式，實現以下功能：
1. 讀入一個主字串mainStr和子字串subStr。
2. 將mainStr中的每一個subStr進行翻轉。
3. 如果subStr在mainStr中沒有出現，則輸出\"SubString not found!\"。
4. 程式最後輸出修改後的mainStr。

範例Input Output：("--------"為說明用，程式不用輸出)
--------------------------
Input：
-------
example word test 
word 
--------------------------
Output：
--------
example drow test
--------------------------*/
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
void reverseSubString(char mainstr[], char substr[]);
int main (void){
    char mainstr[200], substr[50];
    fgets(mainstr, sizeof(mainstr), stdin);
    if(mainstr[strlen(mainstr)-1] =='\n'){
        mainstr[strlen(mainstr)-1] = '\0';
    }
    fgets(substr, sizeof(substr), stdin);
    if(substr[strlen(substr)-1] =='\n'){
        substr[strlen(substr)-1] = '\0';
    }
    reverseSubString(mainstr, substr);
    return 0;
}
void reverseSubString(char mainstr[],char substr[]){
    bool found =false;
    char *pos =strstr(mainstr, substr);
    while(pos != NULL){
        found = true;
        int len = strlen(substr);
        for(int i =0; i< len/2; i++){
        char temp = pos[i];
        pos[i] = pos[len -1-i];
        pos[len-1-i] = temp;
    }
    pos = strstr(pos +len, substr);
    }
    if(!found){
        printf("SubString not found!");
    }
    else{
        printf("%s", mainstr);
    }
}