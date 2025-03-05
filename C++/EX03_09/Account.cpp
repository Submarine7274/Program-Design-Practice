//fig 3.8 Account.cpp

#include<iostream>
#include<string>
#include"Account.h"
using namespace std;

Account::Account(std::string accountName, int initialBalance)
    :name{accountName}{
            if (initialBalance > 0){
                balance = initialBalance;
            }
        }

void Account::setName(std::string accountName){
        name = accountName;
}
string Account::getName(){
        return name;
}
void Account::deposit(int depositAmount){
    if(depositAmount > 0){
        balance += depositAmount;
    }
}
void Account::withdraw(int withdrawalAmount){
    if(withdrawalAmount > 0 && balance >= withdrawalAmount){
            balance -= withdrawalAmount;
    }
}
int Account::getBalance(){
    return balance;
}