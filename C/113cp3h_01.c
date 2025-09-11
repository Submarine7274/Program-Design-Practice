#include <stdio.h>
int main(void) {
    int number, day, month, year;
    float price;
    scanf("%d", &number);
    scanf("%f", &price);
    scanf("%d/%d/%d", &month, &day, &year);
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%4.2f\t\t%02d/%02d/%d",number, price, month, day, year);
    return 0;
}