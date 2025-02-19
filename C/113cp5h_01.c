#include <stdio.h>
int main (void){
    int digit = 0, number = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(number > 9999 || number <1){
        printf("Please enter the whole between 1 and 9999");
        return 0;
    }
    else{
        digit = 1;
    }
    for(int i  = number;i >=10;digit++){
        i /=10;
    }
    if(digit >1){
        printf("The number %d has %d digits",number ,digit);
    }
    else {
        printf("The number %d has %d digit",number ,digit);
    }
    return 0;
}