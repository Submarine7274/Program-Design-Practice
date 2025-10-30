#include<iostream>
#include <chrono>
using namespace std;
using namespace chrono;
unsigned long long recursiveFibonacci(int n);
unsigned long long iterativeFibonacci(int n);
int main(){
    int number;
    unsigned long long fibonacci;
    cin >> number;

    auto start = high_resolution_clock::now();
    cout << "Recursive: " << recursiveFibonacci(number) << endl;
    auto end = high_resolution_clock::now(); 

    duration<double, micro> duration = end - start;
    cout << "Time taken (Recursive): " << duration.count() << " μs" << endl;

    start = high_resolution_clock::now();
    cout << "Iterative: " << iterativeFibonacci(number) << endl;   
    end = high_resolution_clock::now();

    duration = end - start;
    cout << "Time taken (Iterative): " << duration.count() << " μs" << endl;
}

unsigned long long recursiveFibonacci(int n) {
    if (n <= 1) return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

unsigned long long iterativeFibonacci(int n) {
    if (n <= 1) return n;
    unsigned long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        unsigned long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}