// Exercise 11.9 Solution: OvernightPackage.cpp
// Member-function definitions of class OvernightPackage.
#include <stdexcept>
#include "OvernightPackage.h" // OvernightPackage class definition
#include <iostream>
using namespace std;

OvernightPackage::OvernightPackage(const string &sn, const string &sa, const string &sc, 
      const string &ss, int sz, const string &rn, const string &ra, const string &rc, 
      const string &rs, int rz, double w, double c, double o) 
: Package(sn, sa, sc, ss, sz, rn, ra, rc, rs, rz, w, c){
    setOvernightFeePerOunce(o);
}
    void OvernightPackage::setOvernightFeePerOunce( double o ){
        overnightFeePerOunce = o;
    }
    double OvernightPackage:: getOvernightFeePerOunce() const{
        return overnightFeePerOunce;
    }
    double OvernightPackage::calculateCost() const{
        return (Package::getCostPerOunce() + overnightFeePerOunce) * (Package::getWeight());
    }