#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

// Radix Sort
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;

    while (maxVal / exp > 0) {
        // Create buckets for each digit
        vector<vector<int>> buckets(10);

        // Distribute elements into buckets based on current digit
        for (int i = 0; i < arr.size(); i++) {
            buckets[(arr[i] / exp) % 10].push_back(arr[i]);
        }

        // Concatenate buckets back to the array
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i][j];
            }
        }

        exp *= 10;
    }
}

// Exchange Sort
void exchangeSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    const int arraySize = 10000; // Increased dataset size
    vector<int> arr(arraySize);
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = rand() % 10000; // Populate with random data
        cout<< arr[i] << " "; // Print the array elements
    }

    cout << "\n排序演算法比較結果:\n" << endl;
    cout << left << setw(15) << "演算法" << setw(12) << "執行時間" << endl;
    cout << string(30, '-') << endl;

    // Merge Sort
{
    vector<int> arr_merge = arr;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr_merge, 0, arr_merge.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Merge Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    

    // Quick Sort
{
    vector<int> arr_quick = arr;
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr_quick, 0, arr_quick.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Quick Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    // Heap Sort
{
    vector<int> arr_heap = arr;
    auto start = chrono::high_resolution_clock::now();
    heapSort(arr_heap);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Heap Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    // Bubble Sort
{
    vector<int> arr_bubble = arr;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr_bubble);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Bubble Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    // Insertion Sort
{
    vector<int> arr_insert = arr;
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr_insert);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Insertion Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    // Selection Sort
{
    vector<int> arr_select = arr;
    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr_select);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Selection Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    // Radix Sort
{
    vector<int> arr_radix = arr;
    auto start = chrono::high_resolution_clock::now();
    radixSort(arr_radix);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Radix Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    // Exchange Sort
{
    vector<int> arr_exchange = arr;
    auto start = chrono::high_resolution_clock::now();
    exchangeSort(arr_exchange);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << left << setw(15) << "Exchange Sort" << setw(12) << duration.count() <<"微秒"<< endl;
}
    return 0;
}