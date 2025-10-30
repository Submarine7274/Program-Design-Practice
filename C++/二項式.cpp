#include<iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;
unsigned long long recursiveBinomialCoefficient(int n, int k);
unsigned long long iterativeBinomialCoefficient(int n, int k);
int main(){
    int n, k;
    cin >> n >> k;

    auto start = high_resolution_clock::now();
    cout << "Recursive: " << recursiveBinomialCoefficient(n, k) << endl;
    auto end = high_resolution_clock::now(); 

    duration<double, micro> duration = end - start;
    cout << "Time taken (Recursive): " << duration.count() << " μs" << endl;

    start = high_resolution_clock::now();
    cout << "Iterative: " << iterativeBinomialCoefficient(n, k) << endl;   
    end = high_resolution_clock::now();

    duration = end - start;
    cout << "Time taken (Iterative): " << duration.count() << " μs" << endl;
}

unsigned long long recursiveBinomialCoefficient(int n, int k) {
    if (k == 0 || k == n) return 1;
    return recursiveBinomialCoefficient(n - 1, k - 1) + recursiveBinomialCoefficient(n - 1, k);
}

unsigned long long iterativeBinomialCoefficient(int n, int k) {
    vector<unsigned long long> C(k + 1, 0);
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] += C[j - 1];
        }
    }
    return C[k];
}