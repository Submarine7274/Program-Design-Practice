#include<stdio.h>
int main (void){
    char ch;    //宣告字元變數
    float words = 0.0f, charaters = 0.0f;   //宣告字元數及單字數變數
    printf("Enter a sentence: ");   //提示輸入
    while((ch = getchar()) != '\n'){    //讀取字元直到遇到換行字元
        if(ch != ' ' &&ch  != '\t'){    //如果字元不是空白或tab
            charaters++;    //字元數加1
        }
        else if(ch == ' ' ||ch == '\t'){    //如果字元是空白或tab
            words++;    //單字數加1
        }
    }
    printf("Characters: %.0f\n", charaters);    //輸出字元數
    printf("Words: %.0f\n", words+1);   //輸出單字數(加1是因為最後一個單字後沒有空白或tab)
    printf("Average word length: %.1f", charaters / (words+1)); //輸出平均單字長度
    return 0;
}