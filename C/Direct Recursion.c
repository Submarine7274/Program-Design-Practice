#include<stdio.h>

int e(int n , int s){
    if(n == 0 || n == 1){
        return n;
    }
    else{
        return s * e(n - 1 , s) + e (n - 2, s);
    }
}
int main (){
    int n , s;
    scanf("%d", &n);
    scanf("%d", &s);
    printf("%d" , e(n, s));
    return 0;
}