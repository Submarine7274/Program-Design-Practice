#include<stdio.h>
int main (void){
    FILE *p = fopen("test.txt","r+");
    int code,quantity;
    char item[20];
    float price, tot;
    fscanf(p,"%d", &code);
    printf("Code: %d ", code);
    
    fscanf(p,"%s", &item);
    printf("Item: %s ", item);
    
    fscanf(p,"%d", &quantity);
    printf("Quantity: %d ", quantity);
    
    fscanf(p,"%f", &price);
    printf("Price: %.2f ", price);
    
    tot = price*quantity;
    printf("%.2f",tot);
    return 0;
}