#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include"Package.h"
class OvernightPackage : public Package
{
private:
    double overnightDeliveryFee;
public:
    OvernightPackage(const string&,const string&,const string&,const string&,unsigned int,const string&,const string&,const string&,const string&,unsigned int,double,double,double);
    void setOvernightDeliveryFee(double);
    double getOvernightDeliveryFee();
    double calculateCost();
    string toString();
};
#endif