/*做一個兩天包裹的class，繼承了Package這個class，但多了處理費用這個data member，
然後在計算費用的時候，要加上處理費，也就是 重量乘以運費 加上處理費 */
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