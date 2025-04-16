/*先做一個基底class Package 要有sender(送件者)跟recipient(收件者)的名字、地址、市、州、郵遞區號
然後要有重量跟每盎司花費運費的data member
要有計算運費的calculateCost()
要有toString()來顯示結果
*/
#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;
class Package{
    private:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    int senderZIPCode;

    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    int recipientZIPCode;

    double weight;
    double costPerOunce;
//有多少data member 就要有多少set 跟get的function
    public:
    Package(const string&,const string&,const string&,const string&,unsigned int,const string&,const string&,const string&,const string&,unsigned int,double,double);
    void setSenderName(const string&);
    void setSenderAddress(const string&);
    void setSenderCity(const string&);
    void setSenderState(const string&);
    void setSenderZIPCode(int);
    string getSenderName();
    string getSenderAddress();
    string getSenderCity();
    string getSenderState();
    unsigned int getSenderZIPCode();

    void setRecipientName(const string&);
    void setRecipientAddress(const string&);
    void setRecipientCity(const string&);
    void setRecipientState(const string&);
    void setRecipientZIPCode(int);
    string getRecipientName();
    string getRecipientAddress();
    string getRecipientCity();
    string getRecipientState();
    unsigned int getRecipientZIPCode();

    void setWeight(double);
    double getWeight();

    void setCostPerOunce(double);
    double getCostPerOunce();

//計算運費跟輸出結果
    double calculateCost();
    string toString();
};

#endif