// Member-function definitions for class Account.
#include <stdexcept>
#include <iostream>
#include "Account.h" // include definition of class Account
using namespace std;

Account::Account( double b){
    if(b > 0.0){
        balance = b;
    }
    else {
        throw invalid_argument("Balance must greater than 0!!!");
        balance = 0.0;
    }
}
void Account::credit( double c){
    balance += c;
}
bool Account::debit( double d){
    if((balance - d) >= 0){
        balance -= d;
        return true;
    }
    else{
        throw invalid_argument("not enough balance for debit");
        return false;
    }
}
void Account::setBalance( double b){
    if(b > 0.0){
        balance = b;
    }
    else {
        throw invalid_argument("Balance must greater than 0!!!");
        balance = 0.0;
    }
}
double Account::getBalance(){
    return balance;
}