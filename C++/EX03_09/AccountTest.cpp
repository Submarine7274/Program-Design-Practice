//3.9 AccountTest.cpp 測試運行程式
#include<iostream>
#include<string>
#include"Account.h"
using namespace std;

int main(void){
    int withdrawlamount{0}, depositamount{0};                                                   //宣告提款金額與存款金額變數，等等用到
    Account account1{"Jane Green", 50};                                                         //宣告Account class的account1物件，並初始化他的值
    Account account2{"John Blue", 0};                                                           //宣告Account class的account2物件，並初始化他的值

    cout<<"account1: "<<account1.getName()<<" balance is $"<<account1.getBalance()<<endl;       //輸出訊息與得到accout1的 name變數值、balance變數值
    cout<<"account2: "<<account2.getName()<<" balance is $"<<account2.getBalance()<<"\n"<<endl; //輸出訊息與得到accout2的 name變數值、balance變數值

    cout<<"Enter deposit amount for account1: ";                                                //輸出提示訊息
    cin>>depositamount;                                                                         //賦值給depositamount變數
    account1.deposit(depositamount);                                                            //account1呼叫deposit()函式，並傳入depositamount，用意是存款
    cout<<"adding "<<depositamount<<" to account1 balance\n"<<endl;                             //輸出提示訊息

    cout<<"account1: "<<account1.getName()<<" balance is $"<<account1.getBalance()<<endl;       //輸出訊息與得到accout1的 name變數值、balance變數值
    cout<<"account2: "<<account2.getName()<<" balance is $"<<account2.getBalance()<<endl<<"\n"; //輸出訊息與得到accout2的 name變數值、balance變數值

    cout<<"Enter deposit amount for account2: ";                                                //輸出提示訊息
    cin>>depositamount;                                                                         //賦值給depositamount變數
    account2.deposit(depositamount);                                                            //account2呼叫deposit()函式，並傳入depositamount，用意是存款
    cout<<"adding "<<depositamount<<" to account2 balance\n"<<endl;                             //輸出提示訊息

    cout<<"account1: "<<account1.getName()<<" balance is $"<<account1.getBalance()<<endl;       //輸出訊息與得到accout1的 name變數值、balance變數值
    cout<<"account2: "<<account2.getName()<<" balance is $"<<account2.getBalance()<<"\n"<<endl; //輸出訊息與得到accout2的 name變數值、balance變數值

    cout<<"Enter withdrawl amount for account1: ";                                              //輸出提示訊息
    cin>>withdrawlamount;                                                                       //賦值給depositamount變數
    account1.withdraw(withdrawlamount);                                                         //account1呼叫withdraw()函式，並傳入withdrawlamount，用意是提款
    cout<<"subtracting "<<withdrawlamount<<" from account1 balance\n"<<endl;                    //輸出提示訊息

    cout<<"account1 balance: $"<<account1.getBalance()<<endl;                                   //輸出訊息與得到accout1的balance變數值
    cout<<"account2 balance: $"<<account2.getBalance()<<endl<<"\n";                             //輸出訊息與得到accout2的balance變數值

    cout<<"Enter withdrawl amount for account2: ";                                              //輸出提示訊息
    cin>>withdrawlamount;                                                                       //賦值給depositamount變數
    account2.withdraw(withdrawlamount);                                                         //account2呼叫withdraw()函式，並傳入withdrawlamount，用意是提款
    cout<<"subtracting "<<withdrawlamount<<" from account2 balance\n"<<endl;                    //輸出提示訊息

    cout<<"account1 balance: $"<<account1.getBalance()<<endl;                                   //輸出訊息與得到accout1的balance變數值
    cout<<"account2 balance: $"<<account2.getBalance()<<endl;                                   //輸出訊息與得到accout2的balance變數值

    return 0;                                                                                   //程式正常結束
}