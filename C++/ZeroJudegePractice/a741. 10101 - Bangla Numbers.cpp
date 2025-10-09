#include<iostream>
using namespace std;
void bangla(long long n);
int main(void){
    long long number;
    int count = 1;
    while(cin >> number){
        cout << count << ".";
        if(number == 0){
            cout << " 0";
        } else {
            bangla(number);
        }
        cout << endl;
        count++;
    }

}
void bangla(long long n){
    if(n >= 10000000){
        bangla(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if(n >= 100000){
        cout << " " << n/100000 << " lakh";
        n %= 100000;
    }
    if(n >= 1000){
        cout << " " << n/1000 << " hajar";
        n %= 1000;
    }
    if(n >= 100){
        cout << " " << n/100 << " shata";
        n %= 100;
    }
    if(n > 0){
        cout << " " << n;
    }
}
