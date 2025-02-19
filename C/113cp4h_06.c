#include <stdio.h>
int main (void){
    int nums[13]={0}, fs = 0, ss = 0, cd = 0;
    printf("Enter the first 12 digits of an EAN:");
    for(int i = 0; i <= 11; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i = 0; i<=12; i++){
        if (i % 2 == 1 && i <= 11){
            fs += nums[i];
        }
        else if(i <= 10){
            ss += nums[i];
        }
    }
    cd = 9 -((((fs*3) +ss) -1) %10);
    printf("Check digit:%d", cd);
    return 0;
}