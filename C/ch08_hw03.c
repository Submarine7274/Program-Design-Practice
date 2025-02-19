#include <stdio.h>
#include <ctype.h>

void reverseWords(char sentence[], char terminatingChar) {
    int i = 0;
    while (sentence[i] != terminatingChar) {
        i++;
    }

    // 向後搜索找到最後一個單字的開始位置
    for (int j = i - 1; j >= 0; j--) {
        if (!isspace(sentence[j])) {
            // 向前搜尋找到單字的結束位置
            int end = j;
            while (j >= 0 && !isspace(sentence[j])) {
                j--;
            }

            // 印出單字
            for (int k = j + 1; k <= end; k++) {
                putchar(sentence[k]);
            }

            // 印出空格
            if (j >= 0) {
                putchar(' ');
            }
        }
    }

    // 印出終止字符
    putchar(terminatingChar);
}

int main() {
    char sentence[1000];
    char terminatingChar;

    //printf("Input a sentence: \n");

    int i = 0;
    while (1) {
        char c = getchar();
        sentence[i] = c;

        if (c == '.' || c == '?' || c == '!') {
            terminatingChar = c;
            break;
        }

        i++;
    }

    sentence[i + 1] = '\0';

    //printf("Output reversal of sentence: \n");

    // 印出反轉後的單字
    reverseWords(sentence, terminatingChar);

    return 0;
}