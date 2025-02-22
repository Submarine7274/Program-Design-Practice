#include <stdio.h>

// 函式: 刪除排序陣列中的重複元素
int removeDuplicates(int arr[], int n) {
    // 如果陣列為空或只有一個元素，則無需刪除
    if (n == 0 || n == 1) {
        return n;
    }

    // 建立一個臨時陣列來儲存不重複的元素
    int tempArr[n];

    // 將第一個元素複製到臨時陣列中
    tempArr[0] = arr[0];

    // 初始化不重複元素的計數器
    int j = 1;

    // 遍歷整個陣列，跳過重複的元素
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            tempArr[j] = arr[i];
            j++;
        }
    }

    // 複製臨時陣列中的元素回原始陣列
    for (int i = 0; i < j; i++) {
        arr[i] = tempArr[i];
    }

    return j; // 返回新陣列的長度
}

int main(void) {
    int size;

    // 輸入排序陣列的大小
    scanf("%d", &size);

    int sortedArray[size];

    // 輸入排序陣列的元素
    for (int i = 0; i < size; i++) {
        scanf("%d", &sortedArray[i]);
    }

    // 呼叫函式刪除重複元素
    int newSize = removeDuplicates(sortedArray, size);

    // 輸出刪除重複元素後的陣列
    for (int i = 0; i < newSize; i++) {
        printf("%d ", sortedArray[i]);
    }

    return 0;
}