/*存款帳戶 繼承Account 多了利率的data member*/
#include "Account.h"
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
class SavingAccount:public Account{
    private:
    double interestRate;        //利率
    public:
    SavingAccount(double,double);       //第一個參數是初始利率 第二個是利率
    double getInterestRate();
    void setInterestRate(double);
    double calculateInterest();         //計算利率
};
#endif