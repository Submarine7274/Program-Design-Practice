#include<stdio.h>
int sum(int a[], int n);

int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d", sum(a, n));
    return 0;
}

int sum(int a[], int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s += a[i];
    }
    return s;
}