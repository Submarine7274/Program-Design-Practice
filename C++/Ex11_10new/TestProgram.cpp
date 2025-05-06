#include"Account.h"
#include"CheckingAccount.h"
#include"SavingAccount.h"
#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

int main(void){
    vector<Account*> accounts{
        new Account{500},
        new CheckingAccount{1000, 1},
        new SavingAccount{1500,0.01},
    };
    for(Account* accountptr:accounts){
        cout<<"Enter an amount to withdraw"<<endl;
        double amount = 0;
        cin>>amount;
        try{
            accountptr->debit(amount);
        }
        catch(invalid_argument &e){
            cerr<<e.what()<<endl;
        }
        
        cout<<"Enter an amount to deposit"<<endl;
        cin>>amount;
        try{
            accountptr->credit(amount);
        }
        catch(invalid_argument &e){
            cerr<<e.what()<<endl;
        }

        SavingAccount* savingAccountPtr = dynamic_cast<SavingAccount*>(accountptr);
        if(savingAccountPtr != nullptr){
            cout<<"Interest is:"<<savingAccountPtr->calculateInterest()<<endl;
            savingAccountPtr->credit(savingAccountPtr->calculateInterest());
        }
        cout<<"Current balance is :"<<accountptr->getBalance()<<endl;
    }
    for(Account* accountptr:accounts){
        cout<<"Deleting object of:"<<typeid(*accountptr).name()<<endl;
        delete accountptr;
    }
    return 0;
}