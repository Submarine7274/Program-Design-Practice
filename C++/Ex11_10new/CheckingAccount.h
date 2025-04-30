/*支票帳戶，繼承Account 多了手續費的data member*/
#include"Account.h"
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount:public Account{
private:
    double transactionFee;
    void chargeFee();
public:
    CheckingAccount(double,double);     //第一個參數是餘額，第二個參數是手續費
    void credit(double);        
    void debit(double);
    double getTransactionFee();         //其實這邊已經用chargeFee()這個功能性function實作了收手續費的動作，但我還是為了手續費寫了getter跟setter
    void setTransactionFee(double);
};
#endif