//把字母轉換成電話號碼的數字 舊的電話數字上會有對應的字母
#include <stdio.h>
int main (void){
    char ch;    //宣告變數 ch是輸入的字元
    printf("Enter phone number: ");  //提示輸入
    while((ch =getchar()) != '\n'){   //讀取輸入的字元直到遇到換行符號
        switch(ch){ //根據字元輸出對應的數字
            case 'A':       //數字為2的字母
            case 'B':
            case 'C':printf("2");
            break;
            case 'D':    //數字為3的字母
            case 'E':
            case 'F':printf("3");
            break;
            case 'G':    //數字為4的字母
            case 'H':
            case 'I':printf("4");
            break;
            case 'J':   //數字為5的字母
            case 'K':
            case 'L':printf("5");
            break;
            case 'M':   //數字為6的字母
            case 'N':
            case 'O':printf("6");
            break;
            case 'P':   //數字為7的字母
            case 'R':
            case 'S':printf("7");
            break;
            case 'T':   //數字為8的字母
            case 'U':
            case 'V':printf("8");
            break;
            case 'W':   //數字為9的字母
            case 'X':
            case 'Y':printf("9");
            break;
            default:
            printf("%c", ch); //其他字元原樣輸出
            break;
        }
    }
    return 0;
}