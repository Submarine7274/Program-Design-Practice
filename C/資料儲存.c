#include <stdio.h>
#include <string.h>

int main(void) {
    char ss[50] = {0};

    // 使用 fgets 將整行文字輸入到 ss 中
    fgets(ss, sizeof(ss), stdin);

  // 移除換行符號
    size_t len = strlen(ss);
    
    if (len > 0 && ss[len - 1] == '\n') {
        ss[len - 1] = '\0';
        len -= 1;
    }

    // 輸出字串的大小
    printf("%zu", len);

    return 0;
}