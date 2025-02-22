#include<stdio.h>
int fnumber(int f);
int main(void){
    int f;
    scanf("%d", &f);
    printf("%d", fnumber(f));
    return 0;
}
int fnumber(int f){
    if(f<=2){
        return 1;
    }
    else{
        return fnumber(f-1) + fnumber(f-2);
    } 
}