#include <stdio.h>
int main (void){
    const char* vocabulary[]={"Apple", "Banana", "Cherry", "Durian", "Egg", "Fish"};    //宣告字串陣列存放單字
    char character; //宣告使用者輸入的字元變數
    scanf("%c", &character);    //輸入字元
    switch(character){  //使用switch判斷輸入字元
        case 'A':
        case 'a':
        printf("%s", vocabulary[0]);    //輸出對應的單字 記得字串要用%s
        break;
        case 'B':
        case 'b':
        printf("%s", vocabulary[1]);
        break;
        case 'C':
        case 'c':
        printf("%s", vocabulary[2]);
        break;
        case 'D':
        case 'd':
        printf("%s", vocabulary[3]);
        break;
        case 'E':
        case 'e':
        printf("%s", vocabulary[4]);
        break;
        case 'F':
        case 'f':
        printf("%s", vocabulary[5]);
        break;
        default :
        printf("Error");    //輸入錯誤輸出Error
        break;
    }
    return 0;
}