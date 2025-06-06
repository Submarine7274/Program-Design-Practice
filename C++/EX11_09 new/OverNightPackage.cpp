#include"package.h"
#include"OvernightPackage.h"
#include<string>
#include<stdexcept>
#include<sstream>

OvernightPackage::OvernightPackage(const string& newSenderName,
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
    double newCostPerOunce,
    double newOvernightDeliveryFee)
    :Package(newSenderName,newSenderAddress,newSenderCity,newSenderState,newSenderZIPCode,newRecipientName,newRecipientAddress,newRecipientCity,newRecipientState,newRecipientZIPCode,newWeight,newCostPerOunce)
    {
        setOvernightDeliveryFee(newOvernightDeliveryFee);           //一樣把資料檢查交給set檢查
}
void OvernightPackage::setOvernightDeliveryFee(double newOvernightDeliveryFee){
    if(newOvernightDeliveryFee<0){
        throw invalid_argument("Overnight deliver fee must lagger than 0.");
    }
    overnightDeliveryFee = newOvernightDeliveryFee;
}
double OvernightPackage::getOvernightDeliveryFee(){return overnightDeliveryFee;}
double OvernightPackage::calculateCost(){
    return (getOvernightDeliveryFee()+getCostPerOunce())*getWeight();           //連夜運送費是直接加在運費上的 (運費+連夜運送費)*重量
}
/*因為字串的順序有改變，所以我這邊不呼叫package的toString來串接*/
string OvernightPackage::toString(){
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
    <<"\nPackage's overnight delivery fee:$"<<getOvernightDeliveryFee()
    <<"\nDelivery fee:$"<<calculateCost();
    return output.str();
}