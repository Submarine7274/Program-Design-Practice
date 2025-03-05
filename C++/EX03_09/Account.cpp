//3.9 Account.cpp 把member function的功能寫完
#include<iostream>
#include<string>
#include"Account.h"
using namespace std;

Account::Account(std::string accountName, int initialBalance)   //constructor建構子，傳入兩個參數
    :name{accountName}{                                         //只有constructor可以這樣寫，叫做member initializer，在函數的body前面放data member跟初始值
            if (initialBalance > 0){                            //初始存款預設為0，只有傳入參數大於0才會賦值給 balance變數(data member之一)
                balance = initialBalance;
            }
        }

void Account::setName(std::string accountName){                 //這函式是設置帳戶名
        name = accountName;                                     //傳入的參數賦值給name變數(data member之一)
}
string Account::getName(){                                      //這函式是回傳帳戶名
        return name;                                            //回傳name變數，因為他是private，外部不能直接存取
}
void Account::deposit(int depositAmount){                       //這函式是存款功能 傳入一個整數的參數
    if(depositAmount > 0){                                      //資料檢查，存款必須大於0
        balance += depositAmount;                               //傳入的參數加到balance 變數(data member之一)
    }
}
void Account::withdraw(int withdrawalAmount){                   //這函數是提款功能 一樣會傳入一個整數的參數
    if(withdrawalAmount > 0 && balance >= withdrawalAmount){    //資料檢查，提款金額大於0，而且帳戶餘額大於等於提款金額
            balance -= withdrawalAmount;                        //balance變數(data member之一)減掉傳入的參數 
    }
}
int Account::getBalance(){                                      //這函式是回傳餘額
    return balance;                                             //回傳balance變數，因為他是private，外部不能直接存取
}