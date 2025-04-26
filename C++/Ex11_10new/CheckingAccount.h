/*支票帳戶，繼承Account 多了手續費的data member*/
#include"Account.h"
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount:public Account{
private:
    double transactionFee;
    //寫一個功能性function 用Account 的set 把手續費跟餘額寫回去
public:
    CheckingAccount(double,double);     //第一個參數是餘額，第二個參數是手續費
    void credit(double);
    void debit(double);
    double getTransactionFee();
    void setTransactionFee(double);

};
#endif