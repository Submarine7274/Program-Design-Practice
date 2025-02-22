#include <stdio.h>
#include <string.h>

int main(void) {
    char n[20];
    int a;
    scanf("%s %d", n, &a);
    
    // 計算字串的實際大小
    size_t sizeofName = strlen(n) + 1;  // +1 是為了包含 null 結尾字元 '\0'
    
    // 計算整數的大小
    size_t sizeofAge = sizeof(a);
    
    // 計算總大小
    size_t totalSize = sizeofName + sizeofAge;
    
    printf("%zu", totalSize);
    
    return 0;
}