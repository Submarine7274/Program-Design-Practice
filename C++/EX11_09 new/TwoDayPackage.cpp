#include"package.h"
#include"TwoDayPackage.h"
#include<stdexcept>
#include<sstream>

TwoDayPackage::TwoDayPackage(const string& newSenderName,
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
    double newFlatFee)
    : Package(newSenderName,newSenderAddress,newSenderCity,newSenderState,newSenderZIPCode,newRecipientName,newRecipientAddress,newRecipientCity,newRecipientState,newRecipientZIPCode,newWeight,newCostPerOunce)
    {   
        if(newFlatFee<0){
            throw invalid_argument("Flat fee must lagger than 0.");
        }
        setFlatFee(newFlatFee);
}
void TwoDayPackage::setFlatFee(double newFlatFee){
    if(newFlatFee <0){
        throw invalid_argument("Flat fee must lagger than 0.");
    }
    flatFee =newFlatFee;
}
double TwoDayPackage::getFlatFee(){return flatFee;}
double TwoDayPackage::calculateCost(){
    return Package::calculateCost()+getFlatFee();
}
string TwoDayPackage::toString(){
    ostringstream output;
    output<<"Sender's name:"<<getSenderName()
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
    <<"\nTwo day flat fee:$"<<getFlatFee()
    <<"\nDelivery fee:$"<<calculateCost();
    return output.str();
}