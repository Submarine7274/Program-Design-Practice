/*先做一個基底class 叫做 Package 要有sender(送件者)跟recipient(收件者)的名字、地址、市、州、郵遞區號
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
    //寄件人的姓名、地址、城市、州、郵遞區號
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    int senderZIPCode;

    //收件人的姓名、地址、城市、州、郵遞區號
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    int recipientZIPCode;
    //重量跟運費
    double weight;
    double costPerOunce;
    //有多少data member 就要有多少set 跟get的function，要有12個get跟12個set
    public:
    Package(const string&,const string&,const string&,const string&,unsigned int,const string&,const string&,const string&,const string&,unsigned int,double,double);

    //寄件人的set跟get
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

    //收件人的set跟get
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

    //重量
    void setWeight(double);
    double getWeight();
    //運費
    void setCostPerOunce(double);
    double getCostPerOunce();

    //計算運費跟輸出結果
    double calculateCost();
    string toString();
};

#endif