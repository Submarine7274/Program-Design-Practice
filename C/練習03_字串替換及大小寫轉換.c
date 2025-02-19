/*編寫一個程式，實現以下功能：
1. 讀入一個主字串mainStr和子字串subStr。
2. 讀入替換字串replaceStr，並將其轉換為全大寫後替換mainStr中的每一個subStr。
3. 如果subStr在mainStr中沒有出現，則輸出\"SubString not found!\"。
4. 程式最後輸出修改後的mainStr。

範例Input Output：("--------"為說明用，程式不用輸出)
--------------------------
Input：
-------
Hello small world, small
small
tiny 
--------------------------
Output：
--------
Hello TINY world, TINY
--------------------------*/
#include <stdio.h>
#include<string.h>
#include <stdbool.h> 
#include <ctype.h>
void replace(char mainstr[], char substr[], char replacestr[]);
void toUpperCase(char str[]);
int main (void){
    char mainStr[200], subStr[50], replaceStr[50];
    fgets(mainStr, sizeof(mainStr), stdin);
    if(mainStr[strlen(mainStr)-1] == '\n'){
        mainStr[strlen(mainStr)-1] = '\0';
    }
    fgets(subStr, sizeof(subStr),stdin);
    if(subStr[strlen(subStr)-1] == '\n'){
        subStr[strlen(subStr)-1] = '\0';
    }
    fgets(replaceStr, sizeof(replaceStr),stdin);
    if(replaceStr[strlen(replaceStr)-1] == '\n'){
        replaceStr[strlen(replaceStr)-1] = '\0';
    }
    replace(mainStr,subStr,replaceStr);
    return 0;
}
void replace(char mainstr[], char substr[], char replacestr[]){
    bool found = false;
    char *pos = strstr(mainstr, substr);
    int len = strlen(substr);
    char result[200] ="";
    while(pos != NULL){ 
        found = true;
        toUpperCase(replacestr);
        strncat(result, mainstr,pos - mainstr);
        strcat(result, replacestr);
        pos += len;
        mainstr = pos;
        pos = strstr(mainstr, substr);
    }
    if(found){
        strcat(result, mainstr);
        printf("%s", result);
    }
    else{
        printf("SubString not found!");
    }
}
void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}