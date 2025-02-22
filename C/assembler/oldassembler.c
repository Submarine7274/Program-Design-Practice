#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char opcode[10];
    int hexValue;
}OpcodeTable;

const OpcodeTable opTable[]={
    {"ADD",0x18},{"ADDF",0x58},{"ADDR",0x90},{"AND",0x40},
    {"CLEAR",0xB4},{"COMP", 0x28},{"COMPF",0x88}
}

// 函數宣告
void read_lines(FILE *file);
FILE *fileopen(const char *filename);

// 定義 fileopen 函式
FILE *fileopen(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE); // 若檔案無法開啟，結束程式
    }
    printf("File opened successfully.\n");
    return file;
}

// 讀取檔案並逐行處理
void read_lines(FILE *file) {
    char word1[50], word2[50], word3[50],buffer[50]; // 用於存放每行的欄位
    int fieldsRead; // 記錄每行讀取到的欄位數
     // 跳過第一行
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("Error reading the first line or the file is empty.\n");
        return;
    }
    // 使用 fscanf 循環讀取每一行資料
    while (1) {
        // 每次嘗試讀取最多三個欄位
        fieldsRead = fscanf(file, "%s %s %s", word1, word2, word3);

        if (fieldsRead == EOF) {
            break; // 若檔案結束，跳出迴圈
        }

        if (fieldsRead == 3) {
            printf("Label: %-10s Opcode: %-10s Operand: %-10s\n", word1, word2, word3);
        } else if (fieldsRead == 2) {
            printf("Label: %-10s Opcode: %-10s Operand: %-10s\n", "none", word1, word2);
        } else if (fieldsRead == 1) {
            printf("Label: %-10s Opcode: %-10s Operand: %-10s\n", "none", word1, "none");
        }
    }
}

int main(void) {
    FILE *file = fileopen("2.2.txt");
    read_lines(file); // 呼叫正確的函數名稱
    fclose(file); // 關閉檔案
    return 0;
}
