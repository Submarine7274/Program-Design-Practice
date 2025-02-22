#include <iostream>
#include <cmath>

using namespace std;

int sum(int n) {
    int sum = 0;
    n = abs(n);
    while (n > 0) {
        int digit = n % 10; 
        sum += digit; 
        n /= 10;
    }
    return sum;
}

bool isDudeney(int n) {
    if (n < 0)
        return false;
    double cubeRoot = cbrt(n);
    int intCubeRoot = round(cubeRoot); 
    int sumOfCubes = sum(n); 
    if(cubeRoot == sumOfCubes ){
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (isDudeney(number)) {
        cout << number << " is a Dudeney number" << endl;
    } else {
        cout << number << " is not a Dudeney number" << endl;
    }

    return 0;
}
