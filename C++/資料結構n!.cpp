#include<iostream>
#include <chrono>
using namespace std;
using namespace chrono;
unsigned long  long recursiveComputingFactorial(int n);
unsigned long long iterativeComputingFactorial(int n);
int main(){
    int number;
    unsigned long long factorial;
    cin >> number;

    auto start = high_resolution_clock::now();
    cout << "Recursive: " << recursiveComputingFactorial(number) << endl;
    auto end = high_resolution_clock::now(); 

    duration<double, micro> duration = end - start;
    cout << "Time taken (Recursive): " << duration.count() << " μs" << endl;

    start = high_resolution_clock::now();
    cout << "Iterative: " << iterativeComputingFactorial(number) << endl;   
    end = high_resolution_clock::now();

    duration = end - start;
    cout << "Time taken (Iterative): " << duration.count() << " μs" << endl;
}
unsigned long long recursiveComputingFactorial(int n){
    if(n==0) return 1;
    return n*recursiveComputingFactorial(n-1);
}
unsigned long long iterativeComputingFactorial(int n){
    unsigned long long factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
    }
    return factorial;   //
}
