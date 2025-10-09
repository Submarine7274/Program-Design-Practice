#include<iostream>
using namespace std;
int main(void){
    int month, day, result;
    cin>>month>>day;
    result = (month*2 + day) % 3;
    switch(result){
        case 0: cout<<"普通"; break;
        case 1: cout<<"吉"; break;
        case 2: cout<<"大吉"; break;
    }
    return 0;
}