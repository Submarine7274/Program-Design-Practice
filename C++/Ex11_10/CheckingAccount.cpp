// Member-function definitions for class CheckingAccount.
#include <iostream>
#include <stdexcept>
#include "CheckingAccount.h" // CheckingAccount class definition
using namespace std;

CheckingAccount::CheckingAccount(double b, double tf)
:Account(b){
    Account::setBalance(b);
    transactionFee = tf;
}
void CheckingAccount::credit( double c){
    if(c > 0.0){
        Account::credit(c);
    }
    else{
        throw invalid_argument("Credit must greater than 0!!!");
    }
}
bool CheckingAccount::debit( double d){
    if(Account::debit(d)){
    double newbalance;
    newbalance = Account::getBalance() - transactionFee;
    Account::setBalance(newbalance);
    return true;
    }
    else{
        throw invalid_argument("not enough balance for debit");
        return false;
    }
}