#include <stdio.h>
int main (void){
    int nums[11], fs = 0, ss = 0, cd = 0;
    
    scanf("%d", &nums[0]);
    for(int i= 1; i<=5; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i= 6; i<=10; i++){
        scanf("%1d", &nums[i]);
    }
    
    
    for (int i = 0; i <= 10; i++){
        if ((i % 2) == 1){
            ss += nums[i];
        }
        else {
            fs += nums[i];
        }
    }
    //printf("%d\n", fs);
    //printf("%d\n", ss);
    cd = 9 - ((((fs * 3) + ss) - 1) % 10);
    printf("%1d", cd);
    return 0;
}