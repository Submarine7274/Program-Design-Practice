#include<stdio.h>
#include<ctype.h>
void reverse(char s[], char tc){
    int i = 0;
    while(s[i] != tc){ //數一下句子長度
        i++;
    }
    for(int j = i -1 ; j >= 0; j--){//j等於最後一個單字的最後字元
        if(!isspace(s[j])){//如果j不是空白
            int ws = j;//找到最後一個單字的開始字元
            while(j >= 0 && !isspace(s[j])){ //j如果比零大而且不是空白，將j遞減
            j--;
            }
            for(int k = j + 1; k <= ws; k++){//印出單字，K為單字的開始與結束
            putchar(s[k]);
            }
            if(j >= 0){//印出空格
            putchar(' ');
            }
        }
    }
    putchar(tc);//印出句尾的標準符號
}
int main(void){
    char s[1000];
    char tc;
    int i = 0;
    while(1){
        char c = getchar();
        s[i] = c;
        if(c == '.' || c == '?' || c == '!'){
            tc = c;
            break;
        }
        i++;
    }
    s[i + 1] = '\0';
    reverse(s, tc);
    return 0;
}