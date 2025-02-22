// Member-function definitions for class SavingsAccount.
#include <stdexcept>
#include "SavingsAccount.h" // SavingsAccount class definition
using namespace std;

SavingsAccount::SavingsAccount(double b, double in)
:Account(b){
    Account::setBalance(b);
    if(in > 0.0){
        interestRate = in;
    }
    else{
        interestRate = 0.0;
    }
}
double SavingsAccount::calculateInterest(){
    return (Account::getBalance()) * (1+interestRate);
}