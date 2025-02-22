#include <stdio.h>

// 函數原型
int sumArray(int arr[], int size);

int main() {
    int n;

    // 讓使用者輸入整數n
    //printf("Enter the number of elements: ");
    scanf("%d", &n);

    // 宣告一個大小為n的整數陣列
    int arr[n];

    // 讓使用者輸入n個整數，並儲存在陣列中
   //printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 調用函數計算陣列元素的總和並顯示
    int result = sumArray(arr, n);
    printf("%d", result);

    return 0;
}

// 函數定義：計算陣列元素的總和
int sumArray(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}
