#include<stdio.h>
int fe(int n){
    if(n <= 2){
        return 2;
    }
    else {
        return 4 * fe(n - 1) + fe(n - 2);
    }
}
int fo(int n){
    if (n <= 1){
        return 1;
    }
    else {
        return 4 * fo(n - 1) + fo(n -2);
    }
}
int main(){
    int n ;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++){
        printf("%d ", fe(i));
    }
    printf("\n");
    for (int i = 1 ; i <= n ; i++){
        printf("%d ", fo(i));
    }
    return 0;
}