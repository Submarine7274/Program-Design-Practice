//統計一個單字的Scrabble分數
#include <stdio.h>
#include <ctype.h>
int main (void){
    int sum = 0;    //宣告變數 sum是分數
    char ch;    //宣告變數 ch是輸入的字元
    printf("Enter a word: ");   //提示輸入
    while((ch = getchar()) != '\n'){    //讀取輸入的字元直到遇到換行符號
        ch = toupper(ch);   //將字元轉成大寫以便比較
        switch(ch){
            case 'A':case'E':case'I':case'L':case'N':case'O':case'R':case'S':case'T':case'U':   //分數為1的字母
            sum += 1;
            break;
            case 'D':case'G':   //分數為2的字母
            sum += 2;
            break;
            case 'B':case'C':case'M':case'P':    //分數為3的字母
            sum += 3;
            break;
            case 'F':case'H':case'V':case'W':case'Y':   //分數為4的字母
            sum += 4;
            break;
            case 'K':   //分數為5的字母
            sum += 5;
            break;
            case 'J':case'X':   //分數為8的字母
            sum += 8;
            break;
            case 'Q':case'Z':   //分數為10的字母
            sum += 10;
            break;     
        }
    }
    printf("Scrabble value: %d", sum);  //輸出分數
    return 0;
}