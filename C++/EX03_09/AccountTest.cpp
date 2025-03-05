//3.9 AccountTest.cpp 測試運行程式
#include<iostream>
#include<string>
#include"Account.h"
using namespace std;

int main(void){
    int withdrawlamount, depositamount;
    Account account1{"Jane Green", 50};
    Account account2{"John Blue", 0};

    cout<<"account1: "<<account1.getName()<<" balance is $"<<account1.getBalance()<<endl;
    cout<<"account2: "<<account2.getName()<<" balance is $"<<account2.getBalance()<<"\n"<<endl;

    cout<<"Enter deposit amount for account1: ";
    cin>>depositamount;
    account1.deposit(depositamount);
    cout<<"adding "<<depositamount<<" to account1 balance\n"<<endl;

    cout<<"account1: "<<account1.getName()<<" balance is $"<<account1.getBalance()<<endl;
    cout<<"account2: "<<account2.getName()<<" balance is $"<<account2.getBalance()<<endl<<"\n";

    cout<<"Enter deposit amount for account2: ";
    cin>>depositamount;
    account2.deposit(depositamount);
    cout<<"adding "<<depositamount<<" to account2 balance\n"<<endl;

    cout<<"account1: "<<account1.getName()<<" balance is $"<<account1.getBalance()<<endl;
    cout<<"account2: "<<account2.getName()<<" balance is $"<<account2.getBalance()<<"\n"<<endl;

    cout<<"Enter withdrawl amount for account1: ";
    cin>>withdrawlamount;
    account1.withdraw(withdrawlamount);
    cout<<"subtracting "<<withdrawlamount<<" from account1 balance\n"<<endl;

    cout<<"account1 balance: $"<<account1.getBalance()<<endl;
    cout<<"account2 balance: $"<<account2.getBalance()<<endl<<"\n";

    cout<<"Enter withdrawl amount for account2: ";
    cin>>withdrawlamount;
    account2.withdraw(withdrawlamount);
    cout<<"subtracting "<<withdrawlamount<<" from account2 balance\n"<<endl;

    cout<<"account1 balance: $"<<account1.getBalance()<<endl;
    cout<<"account2 balance: $"<<account2.getBalance()<<endl;

    return 0;
}