#include"Inventory.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
enum class Choice{PRINT = 1,UPDATE,NEW,DELETE,END};
Choice enterChoice();
void createDatFile(fstream&);
void updateDateInventory(fstream&);
void newItem(fstream&);
void deleteItem(fstream&);
void outputLine(ostream&,const Inventory&);
int getItem(const char* const); //第一個const 代表了指向的資料不能改，第二個const 表示這個指標不能改

int main(void){
    fstream inOutInventory("Inventory.dat",ios::in||ios::out||ios::binary);
    if(!inOutInventory){
        cerr <<"File could not open."<<endl;
        exit(EXIT_FAILURE);
    }
    Choice inputChoice;
    while((inputChoice = enterChoice()) != Choice::END){
        switch (inputChoice)
        {
        case Choice::PRINT:
            createDatFile(inOutInventory);
            break;
        case Choice::UPDATE:
            updateDateInventory(inOutInventory);
            break;
        case Choice::NEW:
            newItem(inOutInventory);
            break;
        case Choice::DELETE:
            deleteItem(inOutInventory);
            break;
        default:
            cerr<<"Incorrect choice."<<endl;
            break;
        }
    }
}
Choice enterChoice(){
       cout << "\nEnter a choice\n" 
      << "1\tList all tools.\n"
      << "2\tUpdate record\n"
      << "3\tUpdate record\n" 
      << "4\tInsert record\n" 
      << "5\tEndprogram\n? ";
      int menuChoice;
      cin>>menuChoice;
      return static_cast<Choice>(menuChoice);
}
int getItem(const char* const prompt){
    int itemNumber;
    do{
        cout<<prompt<<"(1 - 100): ";
        cin>>itemNumber;
    }while(itemNumber<1||itemNumber >100);
    return itemNumber;
}