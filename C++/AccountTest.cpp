// Create and manipulate Account objects.
#include <iostream>
#include "Account.h"
using namespace std;

// function main begins program execution
int main()
{
   Account account1{"Jane Green", 50};
   Account account2{"John Blue", 0};

   // display initial balance of each object
   cout << "account1: " << account1.getName() << " balance is $"
      << account1.getBalance(); 
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance(); 

   cout << "\n\nEnter deposit amount for account1: "; // prompt
   int depositAmount;
   cin >> depositAmount; // obtain user input
   cout << "adding " << depositAmount << " to account1 balance";
   account1.deposit(depositAmount); // add to account1's balance

   // display balances
   cout << "\n\naccount1: " << account1.getName() << " balance is $"
      << account1.getBalance(); 
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance(); 

   cout << "\n\nEnter deposit amount for account2: "; // prompt
   cin >> depositAmount; // obtain user input
   cout << "adding " << depositAmount << " to account2 balance";
   account2.deposit(depositAmount); // add to account2 balance

   // display balances
   cout << "\n\naccount1: " << account1.getName() << " balance is $"
      << account1.getBalance(); 
   cout << "\naccount2: " << account2.getName() << " balance is $"
      << account2.getBalance() << endl; 

   int withdrawalAmount; // stores withdrawal amount read from user

   cout << "\nEnter withdrawal amount for account1: "; // prompt
   cin >> withdrawalAmount; // obtain user input
   cout << "\nsubtracting " << withdrawalAmount 
      << " from account1 balance\n\n";
   account1.withdraw(withdrawalAmount); // try to subtract from account1

   // display balances
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;

   cout << "\nEnter withdrawal amount for account2: "; // prompt
   cin >> withdrawalAmount; // obtain user input
   cout << "\nsubtracting " << withdrawalAmount 
      << " from account2 balance\n\n";
   account2.withdraw(withdrawalAmount); // try to subtract from account2

   // display balances
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
} 