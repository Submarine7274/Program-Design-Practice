#include <stdio.h>
#include <ctype.h>
int main (void){
    char sentence[1000];    //宣告字元變數陣列 sentence是輸入的句子
    int vowels = 0; //計算母音數量
    printf("Enter a sentence: ");   //輸出提示
    fgets(sentence, 1000, stdin);   //讀取輸入的句子
    for(int i = 0; sentence[i]; i++){   //逐字元檢查句子
        sentence[i] = tolower(sentence[i]); //將字元轉成小寫
        switch(sentence[i]){    //檢查是否為母音
            case 'a': case 'e': case 'i': case 'o': case 'u':   //是母音
            vowels ++;  // 母音數量加1
            break;
        }
    }
    if(vowels > 1){
        printf("Your sentence contains %d vowels.", vowels);    //輸出母音數量
    }
    else{
        printf("Your sentence contains %d vowel.", vowels); 
    }
    return 0;
}

/*另解 這個解不用儲存整個句子 只要一個一個字元讀取並檢查是否為母音
#include <stdio.h>
#include <ctype.h>
int main(void) {
    int t = 0;
    char s;
    printf("Enter a sentence: \n");   
    while ((s = getchar()) != '\n') {
        s = toupper(s);

        if (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') {
            t++;
        }
    }
    printf("Your sentence contains %d vowels.", t);
    return 0;
}
*/