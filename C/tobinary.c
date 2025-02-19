#include <stdio.h>

void print_binary(int n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1); // 使用位運算逐位輸出
    }
}

int main(void) {
    int ip1, ip2, ip3, ip4;

    printf("Enter an IP address (format: x.x.x.x): ");
    if (scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4) != 4) {
        printf("Invalid input format.\n");
        return 1;
    }

    printf("Binary representation:\n");
    print_binary(ip1);
    printf(" ");
    print_binary(ip2);
    printf(" ");
    print_binary(ip3);
    printf(" ");
    print_binary(ip4);
    printf("\n");

    return 0;
}
