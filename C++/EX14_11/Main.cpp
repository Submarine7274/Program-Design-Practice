#include"Inventory.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
enum class Choice{PRINT = 1,UPDATE,NEW,DELETE,END};
Choice enterChoice();
void createTextFile(fstream&);
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
            createTextFile(inOutInventory);
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
    inOutInventory.clear();
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
void createTextFile(fstream& readFromFile){
    ofstream outPrintFile("print.txt",ios::out);
    if(!outPrintFile){
        cerr<<"Error while creating file."<<endl;
        exit(EXIT_FAILURE);
    }
    outPrintFile<<left<<setw(10)<<"Record#"
    <<setw(30)<<"Tool Name"<<setw(12)<<right<<fixed<<"Cost"<<endl;
    readFromFile.seekg(0);
    Inventory tool;
    readFromFile.read(reinterpret_cast<char*>(&tool),sizeof(Inventory));
    //reinterpret_cast是為了將物件轉換成byte的位元組，char*正是一連串的位元組
    //為什麼會需要reinterpret_cast？因為read()跟write()只支援以byte計算的位元組 所以要從Inventory*轉型成char*的型態
    //先用&tool拿到位址，然後用reinterpret_cast<char*>來以這個當作byte(位元組)起點
    //read()的原型是read(char* s,streamsize n),意思是從檔案讀取n個byte 放在s作為起點的位址
    while(!readFromFile.eof()){
        if(tool.getRecordNumber()!=0){
            outputLine(outPrintFile,tool);
        }
        readFromFile.read(reinterpret_cast<char*>(&tool),sizeof(Inventory));
    }
}
void updateDateInventory(fstream& updateFile){
    int recordNumber{getItem("Enter a item to update.")};
    updateFile.seekg(recordNumber*sizeof(Inventory));
    Inventory tool;
    updateFile.read(reinterpret_cast<char*>(&tool),sizeof(Inventory));
    if(tool.getRecordNumber()!= 0){
        outputLine(cout,tool);
        int quantity;
        cin>>quantity;

        int oldQuantity;
        oldQuantity = tool.getQuantity();
        tool.setQuantity(oldQuantity+quantity);
    }
}
void newItem(fstream&);
void deleteItem(fstream&);
void outputLine(ostream&,const Inventory&);