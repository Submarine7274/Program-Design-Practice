#include <string>    // for string
#include <iostream>  // for cout
#include "MotorVehicle.h"
using namespace std;
  MotorVehicle::MotorVehicle(std::string mk, std::string ft, int yom, std::string cl, int ecp)
  // give yearOfManufacture and engineCapacity initial values of 0
    : make{mk}, fuelType{ft}, yearOfManufacture{0}, color{cl}, engineCapacity{0} {
    // check validity of yearOfManufacture and engineCapacity
    // leave defautl values of zero if invalid values provided
    if (yom > 0) {
      yearOfManufacture = yom;
    }
    if (ecp > 0) {
      engineCapacity = ecp;
    }
  }
  void MotorVehicle::setMake(std::string mk) {
    make = mk;
  }
  void MotorVehicle::setFuelType(std::string ft) {
    fuelType = ft;
  }
  void MotorVehicle::setYearOfManufacture(int yom) {
    if (yom > 0) {
      yearOfManufacture = yom;
    }
  }
  void MotorVehicle::setColor(std::string cl) {
    color = cl;
  }
  void MotorVehicle::setEngineCapacity(int ecp) {
    if (ecp > 0) {
      engineCapacity = ecp;
    }
  }
  string MotorVehicle::getMake() {
    return make;
  }
  string MotorVehicle::getFuelType() {
    return fuelType;
  }
  int MotorVehicle::getYearOfManufacture() {
    return yearOfManufacture;
  }
  string MotorVehicle::getColor() {
    return color;
  }
  int MotorVehicle::getEngineCapacity() {
    return engineCapacity;
  }
  void MotorVehicle::displayCarDetails() {
    cout << "Make: " << make << endl;
    cout << "Fuel type: " << fuelType << endl;
    cout << "Year of manufacture: " << 
yearOfManufacture << endl;
    cout << "Color: " << color << endl;
    cout << "Engine capacity: " << 
engineCapacity << endl;
    cout << "---------------------" << endl;
}
/*前面是講義的內容，後面是這次的作業，要寫operator overloading*/
bool MotorVehicle::operator==(const MotorVehicle& mv) const{
    return((make == mv.make)&&(fuelType == mv.fuelType)&&(yearOfManufacture ==mv.yearOfManufacture)&&(color ==mv.color)&&(engineCapacity ==mv.engineCapacity));
    //這邊直接用return 就不用寫判別式來回傳bool，當然要可讀性高的話還是寫判別式，這邊代表所有屬性相等且都相等才會回傳true
}
bool MotorVehicle::operator!=(const MotorVehicle& mv) const{
    return((make != mv.make)||(fuelType != mv.fuelType)||(yearOfManufacture !=mv.yearOfManufacture)||(color !=mv.color)||(engineCapacity !=mv.engineCapacity));
    //這邊跟==不同的地方在於，只要有一種不同，就可以回傳true(也就是不等於成立)
}
bool MotorVehicle::operator>(const MotorVehicle& mv) const{
    return (yearOfManufacture < mv.yearOfManufacture);
    //年紀大的表示出生年比較小
}
ostream& operator<<(std::ostream& out, const MotorVehicle& mv){
    out<<"Make: "<< mv.make <<
      "\nFuel type: " << mv.fuelType <<
      "\nYear of manufacture: " << mv.yearOfManufacture <<
      "\nColor: " << mv.color << 
      "\nEngine capacity: " << mv.engineCapacity<<
      "\n---------------------" << endl;
      return out;
}