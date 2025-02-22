#include <stdio.h>

// 函數原型
void swap(int *a, int *b);
void generatePermutations(int arr[], int start, int end, int *count);

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0;

    // 呼叫 generatePermutations 函數
    generatePermutations(arr, 0, n - 1, &count);

    // 輸出總共的排列組合數量
    printf("%d", count);

    return 0;
}

// 交換兩個數字的函數
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 遞迴生成排列組合的函數
void generatePermutations(int arr[], int start, int end, int *count) {
    if (start == end) {
        // 輸出排列組合
        for (int i = 0; i <= end; i++) {
            //printf("%d ", arr[i]);
        }
        //printf("\n");
        (*count)++;
    } else {
        // 遞迴生成排列組合
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            generatePermutations(arr, start + 1, end, count);
            swap(&arr[start], &arr[i]); // 恢復原始順序
        }
    }
}
