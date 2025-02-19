#include <stdio.h>
int main (void){
    int nums[11], fs = 0, ss = 0, cd = 0;
    printf("Enter the first (single) digit:");
    scanf("%1d", &nums[0]);
    printf("Enter first group of five digits:");
    for(int i = 1; i<= 5; i++){
        scanf("%1d", &nums[i]);
    }
    printf("Enter second group of five digits:");
    for(int i = 6; i<= 10; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i = 0; i<= 10 ;i++){
        if(i % 2 == 0){
            fs += nums[i];
        }
        else{
            ss += nums[i];
        }
    }
    cd = 9 -((((fs * 3) + ss) -1) %10);
    printf("Check digit: %d", cd);
    return 0;
}