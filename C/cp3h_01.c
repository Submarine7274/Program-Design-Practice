#include <stdio.h>
int main (void)
{
    int i, dd, mm, yyyy;
    float p;
    scanf("%d", &i);
    scanf("%f", &p);
    scanf("%d/%d/%d", &mm, &dd, &yyyy);
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\tPrice\t\tDate\n");
    printf("%d\t\t$%4.2f\t\t%02d/%02d/%d\n", i, p, mm, dd, yyyy);
    return 0;
}