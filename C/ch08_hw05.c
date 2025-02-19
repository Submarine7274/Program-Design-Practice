#include <stdio.h>
#include <string.h>

// 函數原型
int areAnagrams(const char *word1, const char *word2);

int main() {
    char firstWord[50], secondWord[50];

    // 輸入兩個單詞
    printf("Enter first word: ");
    scanf("%s", firstWord);

    printf("Enter second word: ");
    scanf("%s", secondWord);

    // 檢查是否為字謎並輸出結果
    if (areAnagrams(firstWord, secondWord)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

// 函數定義：檢查兩個單詞是否為字謎
int areAnagrams(const char *word1, const char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    // 如果兩個單詞長度不同，則它們不可能是字謎
    if (len1 != len2) {
        return 0;
    }

    // 初始化一個字母計數陣列
    int letterCount[26] = {0};

    // 對第一個單詞進行計數
    for (int i = 0; i < len1; i++) {
        letterCount[word1[i] - 'a']++;
    }

    // 對第二個單詞進行減法計數
    for (int i = 0; i < len2; i++) {
        letterCount[word2[i] - 'a']--;
    }

    // 檢查計數陣列是否全為零
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] != 0) {
            return 0;
        }
    }

    // 如果所有計數都為零，則是字謎
    return 1;
}