// Member-function definitions of class TwoDayPackage.
#include <stdexcept>
#include "TwoDayPackage.h" // TwoDayPackage class definition
using namespace std;

TwoDayPackage::TwoDayPackage(const string &sn, const string &sa, const string &sc, 
      const string &ss, int sz, const string &rn, const string &ra, const string &rc, 
      const string &rs, int rz, double w, double c, double f)
    :Package(sn, sa, sc, ss, sz, rn, ra, rc, rs, rz, w, c) {
        setFlatFee(f);
}
    void TwoDayPackage::setFlatFee( double f){
        flatFee = f;
    }
    double TwoDayPackage::getFlatFee() const{
        return flatFee;
    }

    double TwoDayPackage::calculateCost() const{
        return Package::calculateCost() + flatFee;
    }
