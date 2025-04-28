#include"package.h"
#include<stdexcept>
#include<sstream>
#include<string>
using namespace std;
/*這個constructor看起來有點長
string的部分我用reference的方式，這樣就不用傳入值再複製一份給constructor(call by reference),可以去查call by value跟call by refernce的差別
基本上就是把字串的部分直接用member initializer 然後檢查郵遞區號跟重量與運費有沒有符合(郵遞區號不為0，重量跟運費大於0)
member initializer就是
ClassName::ClassName(參數列表)
    : 資料成員1(初值), 資料成員2(初值), 資料成員3(初值)
{
    // constructor 本體
}
    好處是在建立物件的同時，直接賦值，而不是先建立物件後賦值，通常用於不用資料檢查的data member，而且對於const成員跟reference成員，一定要用member initializer
    因為const不能被修改，只能在建立時就設定好數值，reference是綁定某個變數的位置，所以也一定要在一開始就初始
*/
Package::Package(const string& newSenderName,
    const string& newSenderAddress,
    const string& newSenderCity,
    const string& newSenderState,
    unsigned int newSenderZIPCode,
    const string& newRecipientName,
    const string& newRecipientAddress,
    const string& newRecipientCity,
    const string& newRecipientState,
    unsigned int newRecipientZIPCode,
    double newWeight,
    double newCostPerOunce)
    :senderName{newSenderName},senderAddress{newSenderAddress},senderCity{newSenderCity},senderState{newSenderState},
    recipientName{newRecipientName},recipientAddress{newRecipientAddress},recipientCity{newRecipientCity},recipientState{newRecipientState}
    {   //我們把資料檢查的部分，都交給set來執行，這邊直接呼叫就好
        setRecipientZIPCode(newRecipientZIPCode);       //設定收件人郵遞區號
        setSenderZIPCode(newSenderZIPCode);             //設定寄件人郵遞區號
        setWeight(newWeight);               //設定包裹重量
        setCostPerOunce(newCostPerOunce);       //設定運費
    }
//這邊是寄件者的set跟get
void Package::setSenderName(const string& newSenderName){
    senderName = newSenderName;
}
void Package::setSenderAddress(const string& newSenderAddress){
    senderAddress = newSenderAddress;
}
void Package::setSenderCity(const string& newSenderCity){
    senderCity = newSenderCity;
}
void Package:: setSenderState(const string& newSenderState){
    senderState = newSenderState;
}
void Package:: setSenderZIPCode(int newSenderZIPCode){
    if(newSenderZIPCode == 0){
        throw invalid_argument("ZIP Code should not be zero");
    }
    senderZIPCode = newSenderZIPCode;
}
//因為程式比較長，我get的寫法寫成一行文
string Package:: getSenderName(){return senderName;}
string Package:: getSenderAddress(){return senderAddress;}
string Package:: getSenderCity(){return senderCity;}
string Package:: getSenderState(){return senderState;}
unsigned int Package:: getSenderZIPCode(){return senderZIPCode;}

//這邊是收件者的set跟get
void Package::setRecipientName(const string& newRecipientName){
    recipientName = newRecipientName;
}
void Package::setRecipientAddress(const string& newRecipientAddress){
    recipientAddress = newRecipientAddress;
}
void Package::setRecipientCity(const string& newRecipientCity){
    recipientCity = newRecipientCity;
}
void Package:: setRecipientState(const string& newRecipientState){
    recipientState = newRecipientState;
}
void Package:: setRecipientZIPCode(int newRecipientZIPCode){
    if(newRecipientZIPCode == 0){
        throw invalid_argument("ZIP Code should not be zero");
    }
    recipientZIPCode = newRecipientZIPCode;
}
//因為程式比較長，我get的寫法寫成一行文
string Package:: getRecipientName(){return recipientName;}
string Package:: getRecipientAddress(){return recipientAddress;}
string Package:: getRecipientCity(){return recipientCity;}
string Package:: getRecipientState(){return recipientState;}
unsigned int Package:: getRecipientZIPCode(){return recipientZIPCode;}

//這邊是重量跟運費
void Package:: setWeight(double newWeight){
    if(newWeight<=0){
        throw invalid_argument("Weight should largger than 0.");
    }
    weight = newWeight;
}
double Package:: getWeight(){return weight;}

void Package:: setCostPerOunce(double newCost){
    if(newCost<=0){
        throw invalid_argument("Cost should not be free or less than 0.");
    }
        costPerOunce = newCost;
}
double Package:: getCostPerOunce(){return costPerOunce;}
double Package:: calculateCost(){
    return getWeight()*getCostPerOunce();
}
//toString()的寫法參考就好 反正輸出長怎樣自己喜歡即可
string Package:: toString(){
    ostringstream output;
    output<<"\nSender's name:"<<getSenderName()
    <<"\nSender's address:"<<getSenderAddress()
    <<"\nSender's city:"<<getSenderCity()
    <<"\nSender's state:"<<getSenderState()
    <<"\nSender's ZIP code:"<<getSenderZIPCode()
    <<"\n\nRecipient's name:"<<getRecipientName()
    <<"\nRecipient's address:"<<getRecipientAddress()
    <<"\nRecipient's city:"<<getRecipientCity()
    <<"\nRecipient's state:"<<getRecipientState()
    <<"\nRecipient's ZIP code:"<<getRecipientZIPCode()
    <<"\n\nPackage's weight:"<<getWeight()<<"(in ounce)"
    <<"\nPackage's cost per Ounce:$"<<getCostPerOunce()
    <<"\nDelivery fee:$"<<calculateCost();
    return output.str();
}