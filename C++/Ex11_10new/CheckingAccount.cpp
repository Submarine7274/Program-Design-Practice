#include"CheckingAccount.h"
#include<stdexcept>
using namespace std;
CheckingAccount::CheckingAccount(double newbalance,double newtransactionFee)
:Account(newbalance),transactionFee(0.0)
{
    setTransactionFee(newtransactionFee);
}
void CheckingAccount::chargeFee(){
    Account::setBalance(Account::getBalance()-getTransactionFee());
}
void CheckingAccount::credit(double ammount){
    Account::credit(ammount -getTransactionFee());
}
bool CheckingAccount::debit(double ammount){
    if(Account::getBalance()<(ammount+getTransactionFee())){       //如果提款金額加上手續費 超過餘額的話
        throw invalid_argument("Not enough balance.");
    }
    if(ammount <0){
        throw invalid_argument("Can not debit negative number.");
    }
    Account::debit(ammount);       //如果餘額可以負擔提款跟手續費的話 就可以正常執行
    chargeFee();            //收手續費
    return true;
}
double CheckingAccount::getTransactionFee(){return transactionFee;}
void CheckingAccount::setTransactionFee(double newtransactionfee){
    if(newtransactionfee<0){
        throw invalid_argument("Transaction fee must greater than 0.");
    }
    transactionFee = newtransactionfee;
}