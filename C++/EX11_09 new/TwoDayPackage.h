#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include"package.h"
#include<string>
class TwoDayPackage : public Package{
    private:
    double flatFee;

    public:
    TwoDayPackage(const string&,const string&,const string&,const string&,unsigned int,const string&,const string&,const string&,const string&,unsigned int,double,double,double);
    void setFlatFee(double);
    double getFlatFee();
    double calculateCost();
    string toString();
};
#endif