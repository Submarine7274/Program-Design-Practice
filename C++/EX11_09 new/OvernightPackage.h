/*速件(Overnightpackage)繼承了package 多了連夜運送費，
連夜運送費是直接加在運費上的 (運費+連夜運送費)*重量*/
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include"package.h"
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