// Account.h
#include <string>

class Account {
public:
   // Account constructor with two parameters  
    Account(std::string accountName, int initialBalance);
    
   // function that deposits (adds) only a valid amount to the balance
    void deposit(int depositAmount);
    
    
    // function that withdraws (subtracts) only a valid amount from the balance
    void withdraw(int withdrawalAmount);

   // function returns the account balance
    int getBalance();

   // function that sets the name
    void setName(std::string accountName);

   // function that returns the name
    std::string getName();
private:
   std::string name; // account name data member 
   int balance{0}; // data member with default initial value
}; // end class Account