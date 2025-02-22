#include <stdio.h>
int main (void){
    int nums[11], fs = 0, ss =0, ts =0, cd =0;
    scanf("%1d", &nums[0]);
    for(int i = 1; i <=5; i++){
        scanf("%1d", &nums[i]);
    }
    for(int i = 6; i <=10; i++){
        scanf("%1d", &nums[i]);
    }
    for (int i = 0; i <= 10; i++){
        if ((i % 3) == 0){
            fs += nums[i];
        }
        else if(i % 3 == 1){
            ss += nums[i];
        }
        else{
            ts += nums[i];
        }
    }
    //printf("%d\n", fs);
    //printf("%d\n", ss);
    //printf("%d\n", ts);
    cd = 9 -((((fs*3)+ss +ts)-1) % 10);
    printf("%d", cd);
    return 0;
}