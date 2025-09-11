#include<stdio.h>
    int main (void)
    {
        int numericalGrade, letterGrade;    //宣告數字成績與字母成績變數
        printf("Enter a numerical grade: ");    //提示輸入數字成績
        scanf("%d", &numericalGrade);   //讀取數字成績
        letterGrade = numericalGrade / 10;  //計算字母成績
        switch(letterGrade){    //根據字母成績輸出對應的字母等級
                case 6: printf("Letter grade: D"); break;
                case 7: printf("Letter grade: C"); break;
                case 8: printf("Letter grade: B"); break;
                case 9: case 10: printf("Letter grade: A"); break;
                default: printf("Letter grade: F"); break;
        }
        return 0;
    }