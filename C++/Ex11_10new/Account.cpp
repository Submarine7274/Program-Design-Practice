#include"Account.h"
#include<stdexcept>
#include<iostream>
using namespace std;
Account::Account(double newBalance):balance(0.0)
{
    setBalance(newBalance);
}
double Account::getBalance(){return balance;}
void Account::setBalance(double newBalance){
    if(newBalance <0){
        balance = 0;
        throw invalid_argument("Balance should not less than 0.");
    }
    balance = newBalance;
}
void Account::credit(double amount){
    if(amount <0){
        throw invalid_argument("Credit should not less than 0.");
    }
    balance += amount;
}
bool Account::debit(double amount){
    if(amount >balance){
        cout<<"Not enough balance."<<endl;
        return false;
    }
    balance -= amount;
    return true;
}