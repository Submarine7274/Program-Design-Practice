//重頭戲來了 random access的開檔、新增、更新、刪除、以及輸出成txt檔

#include"Inventory.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include <cstdlib> 
#include<sstream>
using namespace std;

enum class Choice{PRINT = 1,UPDATE,NEW,DELETE,END};         //這是要執行哪個function的選項
enum class Option{yes = 1,no};              //這是要不要初始化的選項

Choice enterChoice();           //我照課本寫的，他只是想秀回傳Enum class的東西
void createTextFile(fstream&);          //輸出成TXT檔
void updateDateInventory(fstream&);         //更新某個物品的數量(我懶得更新價格)
void newItem(fstream&);             //新增一項物品
void deleteItem(fstream&);          //刪除一項物品
void outputLine(ostream&,const Inventory&);         //輸出一行格式定義好的物品
int getItem(const char* const); //第一個const 代表了指向的資料不能改，第二個const 表示這個指標不能改，這個function是要輸入編號後，驗證編號有沒有在範圍內

void initializeInventoryFile();         //這個是初始化，會把二進位檔寫入100筆空的物品

int main(void){
    //這邊是選擇要不要初始化
    cout<<"initialize .dat File?(1 for yes/2 for no)"<<endl;
    int menuOption;
    cin>>menuOption;

    switch (menuOption)
    {
    case 1:
        initializeInventoryFile();
        break;
    case 2:
        break;
    default:
        break;
    }


    fstream inOutInventory("hardware.dat",ios::in | ios::out | ios::binary);        //開啟二進制的檔案，請記得因為OS系統的安全限制，要先創檔案 hardware.dat

    if(!inOutInventory){             //開不起來的話，會輸出這行，程式也會結束
        cerr <<"File could not open."<<endl;
        exit(EXIT_FAILURE);
    }

    Choice inputChoice;         //Choice class的變數 叫做inputChoice

    while((inputChoice = enterChoice()) != Choice::END){        //如果不是END，就會一直讓你輸入選項
        switch (inputChoice){
        case Choice::PRINT:         //這邊是用Enum類別當成switch的case
            createTextFile(inOutInventory);     //呼叫輸出成TXT的函式
            break;
        case Choice::UPDATE:
            updateDateInventory(inOutInventory);        //呼叫更新物品的函式
            break;
        case Choice::NEW:
            newItem(inOutInventory);        //呼叫新增物品的函式
            break;
        case Choice::DELETE:
            deleteItem(inOutInventory);     //呼叫刪除物品的函式
            break;
        default:
            cerr<<"Incorrect choice."<<endl;        //錯誤的指令
            break;
        }
    }
    inOutInventory.clear();         //這是為了重置檔案狀態，到達結尾、輸入或輸出出現問題之類的
    inOutInventory.close();         //關檔案
    return 0;
}

Choice enterChoice(){
       cout << "\nEnter a choice\n" 
        << "1\tstore a formatted text file of items\n"
        << "\tcalled \"print.txt\" for printing\n"
        << "2\tUpdate a record\n"
        << "3\tInsert a record\n"
        << "4\tDelete a record\n"
        << "5\tEnd program\n ";
        //這邊是使用提示
      int menuChoice;
      cin>>menuChoice;
      return static_cast<Choice>(menuChoice);       //把cin進來的int轉型成enum類別的選項
}

int getItem(const char* const prompt){          //這是為了驗證編號式1~100存在的函式
    int itemNumber;
    do{
        cout<<prompt<<"(1 - 100): ";
        cin>>itemNumber;
    }while(itemNumber<1||itemNumber >100);
    return itemNumber;
}

void createTextFile(fstream& readFromFile){         //這是為了將二進制檔案的內容，輸出成人看得懂的TXT檔
    
    ofstream outPrintFile("print.txt", ios::out);           //開啟TXT檔，記得ios::out，不然一開檔會直接清空原有內容
    if(!outPrintFile){          //開檔失敗的處理
        cerr << "File could not be created." << endl;
        exit(EXIT_FAILURE);
    }
    //這裡是輸出標題文字
    outPrintFile << left << setw(10) << "Record#"       
                 << setw(30) << "Tool Name"
                 << setw(12) << right << fixed << "Cost"
                 << setw(12) << "Quantity" << endl;
    
    readFromFile.clear();       //先重置傳入的二進位檔
    readFromFile.seekg(0);      //從頭開始讀取

    Inventory tool;
    readFromFile.read(reinterpret_cast<char*>(&tool),sizeof(Inventory));        //二進制檔案讀一筆資料進來

    while(!readFromFile.eof()){         //只要不到檔案結尾
        if(tool.getRecordNumber() != -1){       //有編號代表有資料，所以輸出
            outputLine(outPrintFile, tool);
        }
        readFromFile.read(reinterpret_cast<char*>(&tool),sizeof(Inventory));        //讀下一筆
    }

    outPrintFile.close();           //關檔
    cout << "print.txt created."<<endl;         //提示這個函示有正常執行
}
void updateDateInventory(fstream& updateFile){          //更新某一筆資料
     int recordNumber{getItem("Enter a item to update.")};          //把提示詞傳給getItem，直到輸入1~100之間的數字
    updateFile.seekg((recordNumber - 1) * sizeof(Inventory));       //第一筆資料是從0的位置開始擺，所以這邊才-1，然後中間經過了幾筆資料，所以乘上這個class的大小
    
    Inventory tool;
    updateFile.read(reinterpret_cast<char*>(&tool), sizeof(Inventory));     //把那筆資料讀進來

    if (tool.getRecordNumber() != -1) {             //不是-1代表有編號
        outputLine(cout, tool);             //輸出成一行
        //這邊是更新數量，更新價格我懶得寫了
        int quantity;
        cout << "Enter quantity to add: ";
        cin >> quantity;

        tool.setQuantity(tool.getQuantity() + quantity);
        outputLine(cout, tool);         //再輸出成一行看結果

        updateFile.seekp((recordNumber - 1) * sizeof(Inventory));       //移動指標到定點
        updateFile.write(reinterpret_cast<char*>(&tool), sizeof(Inventory));        //寫到二進位檔裡

        cout << "Update successful.\n";
    } else {
        cout << "No such record.\n";
    }
}
void newItem(fstream& insertInFile){            //新增一項物品
    int recordNumber{getItem("Enter new item number.")};        //把提示詞傳給getItem，直到輸入1~100之間的數字
    insertInFile.seekg((recordNumber-1)*sizeof(Inventory));         //第一筆資料是從0的位置開始擺，所以這邊才-1，然後中間經過了幾筆資料，所以乘上這個class的大小
    Inventory tool;
    insertInFile.read(reinterpret_cast<char*>(&tool),sizeof(Inventory));        //把那筆資料讀進來

    if(tool.getRecordNumber()==-1){         //-1代表是空白的，可以寫新的進去
        //這邊就是輸入資料
        string newToolName;
        int newQuantity;
        double newCost;
        cout << "Enter tool name, cost and quantity:";

        cin>>setw(30)>>newToolName;
        cin >> newCost >> newQuantity;

        tool.setToolName(newToolName);
        tool.setCost(newCost);
        tool.setQuantity(newQuantity);
        tool.setRecordNumber(recordNumber);

        insertInFile.seekp((recordNumber-1)*sizeof(Inventory));     //移動指標到定點
        insertInFile.write(reinterpret_cast<char*>(&tool),sizeof(Inventory));       //寫到二進位檔裡

        cout << "New item added.\n";
    }
    else{
        cerr<<"Record#"<<recordNumber<< "already exists.\n";
    }
    
}
void deleteItem(fstream& deleteFromFile){           //刪除某一筆資料，比較好玩的地方是，他不是真的刪除，而是用空白的取代
    int recordNumber = getItem("Enter item number to delete");
    deleteFromFile.seekg((recordNumber - 1) * sizeof(Inventory));           //找到該筆位置
    Inventory tool; 
    deleteFromFile.read(reinterpret_cast<char*>(&tool), sizeof(Inventory));         //讀取該筆資料

    if(tool.getRecordNumber() != -1){
        Inventory blankTool; // 預設為 recordNumber = -1，表示空白，用空白的取代這筆資料
        deleteFromFile.seekp((recordNumber - 1) * sizeof(Inventory));
        deleteFromFile.write(reinterpret_cast<const char*>(&blankTool), sizeof(Inventory));
        cout << "Item #" << recordNumber << " deleted.\n";
    }
    else{
        cerr << "Item #" << recordNumber << " is empty.\n";
    }
}
void outputLine(ostream& output,const Inventory& tool){     //格式化的輸出而已，setw是寬度，right left 是置右至左，fixex適用小數點顯示，setprecision是小數點位數
    output << left << setw(10) << tool.getRecordNumber()
           << setw(30) << tool.getToolName()
           << setw(12) << right << fixed << setprecision(2)<< tool.getCost() 
           << setw(12)<< tool.getQuantity() << endl;
}
void initializeInventoryFile() {        //二進制檔案要初始化，這邊新增100筆空白資料
    std::ofstream outFile("hardware.dat", std::ios::binary);
    if (!outFile) {
        std::cerr << "Cannot create hardware.dat file." << std::endl;
        exit(EXIT_FAILURE);
    }
    Inventory emptyTool;  // 預設建構子：recordNumber = -1, 表示空白記錄
    for (int i = 0; i < 100; ++i) {
        outFile.write(reinterpret_cast<const char*>(&emptyTool), sizeof(Inventory));
    }
    outFile.close();
}