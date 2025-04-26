#include"SavingAccount.h"
#include<stdexcept>
using namespace std;
SavingAccount::SavingAccount(double newbalance, double newInterestRate)
:Account(newbalance),interestRate(0.0)        //這裡是呼叫父類別的建構子，而不是建立一個父類別的物件
{
    setInterestRate(newInterestRate);
}
double SavingAccount::getInterestRate(){return interestRate;}
void SavingAccount::setInterestRate(double newInterestRate){
    if(newInterestRate<0){
        throw invalid_argument("Interest rate should not less than 0.");
    }
    interestRate = newInterestRate;
}
double SavingAccount::calculateInterest(){
    return getBalance()*getInterestRate();
}