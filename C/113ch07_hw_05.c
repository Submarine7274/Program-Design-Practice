#include <stdio.h>
#include <ctype.h>
int main (void){
    char firstName[100], lastName[100], initial;    //宣告變數 firstname是姓名 lastname是名字 initial是首字母
    printf("Enter a first and last name: ");    //提示輸入
    scanf("%s", firstName);  //讀取姓名
    scanf("%s", lastName);  //讀取名字
    initial = toupper(firstName[0]);    //將姓名的第一個字母轉成大寫
    printf("%s, %c.", lastName, initial);   //輸出格式為 名字, 姓氏首字母.
    return 0;
}