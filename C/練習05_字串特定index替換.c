/*編寫一個程式，實現以下功能：
1. 讀入一個主字串mainStr。
2. 再讀入一個子字串subStr。
3. 再讀入一個整數index，指定index位置。(index從0開始，代表mainStr的第幾個字，以空白分隔)
4. 再讀入替換字串replaceStr，替換index之後第一次出現的子字串subStr。(不包含index所指定的位置)
5. 如果subStr在指定位置index後找不到，則輸出\"SubString not found!\"。
6. 程式最後輸出修改後的mainStr。

範例Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
Hello world world 
world 
1 
earth
-------------------------- 
Output： 
-------- 
Hello world earth
--------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void indexreplace(char mainstr[], char substr[],char replacestr[],int index);
int main (void){
    char mainStr[200], subStr[50], replaceStr[50];
    int index = 0;
    fgets(mainStr, sizeof(mainStr), stdin);
    if(mainStr[strlen(mainStr)-1] == '\n'){
        mainStr[strlen(mainStr)-1] = '\0';
    }
    fgets(subStr, sizeof(subStr),stdin);
    if(subStr[strlen(subStr)-1] == '\n'){
        subStr[strlen(subStr)-1] = '\0';
    }
    scanf("%d", &index);
    indexreplace(mainStr, subStr, replaceStr,index);
    return 0;
}
void indexreplace(char mainstr[], char substr[],char replacestr[],int index){
    bool found = false;
    char result[250];
    char *tokens[200];
    char *token = strtok(mainstr, " ");
    int tokencount = 0;
    int substrength = strlen(substr);
    bool replaced = false;
    while(token != NULL){
        tokens[tokencount++] = token;
        token = strtok(NULL, " ");
    }
    for(int i =0; i <= tokencount; i++){
        if(i >index&&!replaced&&strcmp(tokens[i],substr) ==0){
            strcat(result, replacestr);
        }
    }

    //換別台電腦寫
}   