//Account.h 函數的原型以及data member
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
class Account{
    public:
    Account(std::string accountName, int initialBalance);
    
    void setName(std::string accountName);
    std::string getName();

    void deposit(int depositAmount);
    int getBalance();

    void withdraw(int withDrawAmount);

    private:
    std::string name;
    int balance{0};
};                                          //注意class的{}後面要有;

#endif