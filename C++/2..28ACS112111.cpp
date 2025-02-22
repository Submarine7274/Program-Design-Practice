#include<iostream>
int main(){
    int number{0};
    int digit{0};
    int div{10000};
    using namespace std;
    cout << "Enter a five digits number: ";
    cin >> number;
    for(int i = 0; i < 5; i++){
        digit = number / div;
        cout << digit <<"   ";
        number = number % div;
        div /= 10;
    }
    return 0;
}