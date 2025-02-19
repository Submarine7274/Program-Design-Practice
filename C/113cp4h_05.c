#include <stdio.h>
int main (void){
    int nums[11]={0}, fs = 0, ss = 0, cd = 0;
    printf("Enter the first 11 digits of a UPC:");
    for(int i = 0; i <= 10; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i = 0; i<=10; i++){
        if (i % 2 == 0){
            fs += nums[i];
        }
        else{
            ss += nums[i];
        }
    }
    cd = 9 -((((fs*3) +ss) -1) %10);
    printf("Check digit:%d", cd);
    return 0;
}