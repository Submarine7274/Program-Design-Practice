#include <stdio.h>

int arrsum (int arr[], int n);
int main (void){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i <n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", arrsum(arr,n));
    return 0;
}
int arrsum (int arr[], int n){
    int sum =0;
    for(int i = 0; i<n; i++){
        sum +=arr[i];
    }
    return sum;
}