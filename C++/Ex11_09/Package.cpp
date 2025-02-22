// Member-function definitions of class Package.
#include <stdexcept>
#include "Package.h" // Package class definition
using namespace std;

Package::Package( const string &sn, const string &sa, const string &sc, 
      const string &ss, int sz, const string &rn, const string &ra, const string &rc, 
      const string &rs, int rz, double w, double c){
        senderName = sn;
        senderAddress = sa;
        senderCity = sc;
        senderState = ss;
        senderZIP = sz;
        recipientName = rn;
        recipientAddress = ra;
        recipientCity = rc;
        recipientState = rs;
        recipientZIP = rz;
        
        if(w > 0.0 && c > 0.0){
            weight = w;
        costPerOunce = c;
        }
        else{
             weight = 0.0;
        costPerOunce = 0.0;
        }
        
      }
    void Package::setSenderName(const string &sn){
        senderName = sn;
    }
    string Package::getSenderName() const{
        return senderName;
    }
    void Package::setSenderAddress(const string &sa){
        senderAddress = sa;
    }
    string Package::getSenderAddress() const{
        return senderAddress;
    }
    void Package::setSenderCity(const string &sc){
        senderCity = sc;
    }
    string Package::getSenderCity() const{
        return senderCity;
    }
    void Package::setSenderState(const string &ss){
        senderState = ss;
    }
    string Package::getSenderState() const{
        return senderState;
    }
    void Package::setSenderZIP(int sz){
        senderZIP = sz;
    }
    int Package::getSenderZIP() const{
        return senderZIP;
    }
    
    void Package::setRecipientName(const string &rn){
        recipientName = rn;
    }
    string Package::getRecipientName() const{
        return recipientName;
    }
    void Package::setRecipientAddress(const string &ra){
        recipientAddress = ra;
    }
    string Package::getRecipientAddress() const{
        return recipientAddress;
    }
    void Package::setRecipientCity(const string &rc){
        recipientCity = rc;
    }
    string Package::getRecipientCity() const{
        return recipientCity;
    }
    void Package::setRecipientState(const string &rs){
        recipientState = rs;
    }
    string Package::getRecipientState() const{
        return recipientState;
    }
    void Package::setRecipientZIP(int rz){
        recipientZIP = rz;
    }
    int Package::getRecipientZIP() const{
        return recipientZIP;
    }
    void Package::setWeight( double w){
        weight = w;
    }
    double Package::getWeight() const{
        return weight;
    } 
    void Package::setCostPerOunce( double c){
        costPerOunce = c;
    } 
    double Package::getCostPerOunce() const{
        return costPerOunce;
    }
    double Package::calculateCost() const{
        return weight * costPerOunce;
    }