#include <stdio.h>

int main(void) {
    int item_number, month, day, year;
    float unit_price;


    scanf("%d", &item_number);

   
    scanf("%f", &unit_price);

    scanf("%d/%d/%d", &month, &day, &year);


    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\tPrice\t\tDate\n");
    printf("%d\t\t$%4.2f\t\t%02d/%02d/%d\n", item_number, unit_price, month, day, year);

    return 0;
}