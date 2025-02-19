#include<stdio.h>
#include<stdbool.h>
int main (void){
    int number, digit;
    bool digitSeen[10]={false};
    printf("Enter a number: ");
    scanf("%d", &number);
    while(number >0){
        digit = number %10;
        if(digitSeen[digit]){
            printf("Repeated digit\n");
            return 0;
        }
        digitSeen[digit] = true;
        number /= 10;
    }
    printf("No repeated digit\n");
    return 0;
}