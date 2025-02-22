#include <stdio.h>
int main(void) {
    int num, d, m, y;
    float price;
    scanf("%d", &num);
    scanf("%f", &price);
    scanf("%d/%d/%d", &m, &d, &y);
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%4.2f\t\t%02d/%02d/%d",num, price, m, d, y);
    return 0;
}