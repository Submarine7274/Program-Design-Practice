#include<stdio.h>
double fact(int n);
int main (void){
    int n;
    double e = 1.0;
    scanf("%d", &n);
    if(n >=0 && n <=7){
        for(int i = 1; i <= n ;i++){
            e += 1.0/fact(i);
        }
    }
    else{
        return 0;
    }
    printf("%.4f", e);
    return 0;
}
double fact(int n){
    double result = 1.0;
    for(int i =1; i<= n; i++){
        result *= i;
    }
    return result;
}