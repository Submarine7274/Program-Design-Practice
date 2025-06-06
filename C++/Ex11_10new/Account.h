/*銀行帳戶 要能存款跟提款還有查詢餘額 初始要有餘額 data member要有餘額*/
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account{
    private:
    double balance{0};
    public:
    Account(double);        //傳入參數是初始餘額
    virtual ~Account()=default;
    virtual void credit(double);        //存款
    virtual bool debit(double);         //提款 因應後面的題目需求 回傳bool值
    double getBalance();        //餘額查詢
    void setBalance(double);          //理論上是只能存款跟提款，但這邊也提供set
};
#endif