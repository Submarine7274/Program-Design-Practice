#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; 

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false; 
        }
    }

    return true; 
}

int main() {
    int count = 0;

    for (int num = 2; num <= 10000; ++num) {
        if (isPrime(num)) {
            cout << num << " ";
            ++count;

            
            if (count % 10 == 0) {
                cout << endl;
            }
        }
    }
    cout << "\nWe have "<< count << " prime numbers between 1 and 10000"<< endl;
    return 0;
}
