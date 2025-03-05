//3.9 AccountTest.cpp
#include<iostream>
#include<string>
#include"Account2.h"
using namespace std;

int main(void){
    int withdrawamount, depositamount;
    Account account1{"John", 1000};
    Account account2{"David", 2000};
    account1.show();
    account2.show();
    cout<<"Enter withdraw amount: "<< endl;
    cin>>withdrawamount;
    account1.withdraw(withdrawamount);
    account2.withdraw(withdrawamount);
    account1.show();
    account2.show();
    cout<<"Enter deposit amount: "<< endl;
    cin>>depositamount;
    account1.deposit(depositamount);
    account2.deposit(depositamount);
    account1.show();
    account2.show();
    return 0;
}