#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>
using namespace std;
class Inventory{
    
    public:
    static const size_t LENGTH =30;
    Inventory(int=-1,const std::string& ="",int=0,double=0.0);
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
    char toolName[LENGTH];
    int quantity;
    double cost;
};
#endif