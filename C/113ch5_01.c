#include <stdio.h>
int main (void){
    int num;
    const char* month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    scanf("%d", &num);
    if(num > 12 || num <= 0){
        printf("error");
    }
    else {
        num -= 1;
        printf("%s", month[num]);
    }
    return 0;
}