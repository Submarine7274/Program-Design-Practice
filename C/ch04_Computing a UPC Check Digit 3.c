#include <stdio.h>
int main (void){
    int nums[13], fs=0, ss=0, ts=0, cd=0;
    scanf("%1d", &nums[0]);
    for(int i = 1; i <= 4; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i = 5; i <= 8; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i = 9; i <= 12; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i = 0; i <= 12; i++){
        if(i % 2 == 0 && i <= 8){
            fs += nums[i];
        }
        else if(i % 2 == 1 && i <= 7){
            ss += nums[i];
        }
        else{
            ts += nums[i];
        }
    }
    //printf("%d\n", fs);
    //printf("%d\n", ss);
    //printf("%d\n", ts);
    
    cd = 9-((((fs *2) +ss +ts) +5) %7);
    printf("%d", cd);
    return 0;
}