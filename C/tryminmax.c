#include <stdio.h>
#define N 10

void minmax(int a[], int n,int *min, int *max);

int main (void){
    int array[N], min, max;
    printf("Enter %d numbers\n", N);
    for(int i =0; i<N; i++){
        scanf("%d", &array[i]);
    }
    minmax(array, N, &min, &max);
    printf("min: %d max: %d", min, max);
    return 0;
}
void minmax(int a[], int n,int *min, int *max){
    *min = *max = a[0];
    for(int i =0; i <n; i++){
        if(a[i] >*max){
            *max = a[i];
        }
        else if(a[i]<*min){
            *min = a[i];
        }
    }
}