#include<stdio.h>
int main (void){
    FILE *p = fopen("test.txt","w+");
    int code,quantity;
    char item[20];
    float price, tot;
    printf("Enter Code: ");
    scanf("%d", &code);
    
    printf("Enter Item: ");
    scanf("%s", &item);
    
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    
    printf("Enter Price: ");
    scanf("%f", &price);
    
    tot = price*quantity;
    fprintf(p,"%d\t%s\t%d\t%.2f\t%.2f",code,item,quantity,price,tot);
    return 0;
}