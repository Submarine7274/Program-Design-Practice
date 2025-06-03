//題目要我們做出商店賣了甚麼東西，要有該物品的編號、名字、數量、金額
//做這題目之前，因為OS系統的安全限制，請先創兩個檔案 hardware.dat 跟print.txt 避免開檔失敗
#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>
using namespace std;
class Inventory{
    
    public:
    static const size_t LENGTH =30;         //定義名字的長度
    Inventory(int=-1,const std::string& ="",int=0,double=0.0);      //用-1代表是空白的物品欄 名字 數量 金額
    //基本的getter跟setter
    int getRecordNumber() const;
    void setRecordNumber(int);

    string getToolName() const;
    void setToolName(const string&);

    int getQuantity() const;
    void setQuantity(int);

    double getCost() const;
    void setCost(double);

    private:
    int recordNumber;
    char toolName[LENGTH];      //不能用string的原因是我們要寫入二進制的檔案
    int quantity;
    double cost;
};
#endif