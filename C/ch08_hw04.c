#include <stdio.h>

void encrypt(char *message, int shift);
void decrypt(char *message, int shift);

int main() {
    char message[80];
    int shift;

    // 輸入原始訊息和位移量
    printf("Enter message to be encrypted: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    // 加密並輸出
    printf("Encrypted message: ");
    encrypt(message, shift);
    printf("%s", message);

    // 解密並輸出
    //printf("\nEnter shift amount for decryption: ");
    //scanf("%d", &shift);
    //decrypt(message, shift);
    //printf("Decrypted message: %s", message);

    return 0;
}

void encrypt(char *message, int shift) {
    while (*message) {
        if ('A' <= *message && *message <= 'Z') {
            *message = ((*message - 'A') + shift) % 26 + 'A';
        } else if ('a' <= *message && *message <= 'z') {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }
        message++;
    }
}

void decrypt(char *message, int shift) {
    // 解密實際上就是加密的反向操作
    // 只需將位移量取負即可
    encrypt(message, -shift);
}
