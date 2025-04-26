#include"CheckingAccount.h"
#include<stdexcept>
using namespace std;
CheckingAccount::CheckingAccount(double newbalance,double newtransactionFee)
:Account(newbalance),transactionFee(0.0)
{
    setTransactionFee(newtransactionFee);
}
void CheckingAccount::credit(double ammount){
    Account::credit(ammount -getTransactionFee());
}
void CheckingAccount::debit(double ammount){
    if(Account::debit(ammount +getTransactionFee()) ==0){       //如果提款金額加上手續費 超過餘額的話
        throw invalid_argument("");     //因為在Account已經有cout原因了 這邊就直接輸出空白
    }
    Account::debit(ammount +getTransactionFee());       //如果餘額可以負擔提款跟手續費的話 就可以正常執行
}
double CheckingAccount::getTransactionFee(){return transactionFee;}
void CheckingAccount::setTransactionFee(double newtransactionfee){
    if(newtransactionfee<0){
        throw invalid_argument("Transaction fee must greater than 0.");
    }
    transactionFee = newtransactionfee;
}