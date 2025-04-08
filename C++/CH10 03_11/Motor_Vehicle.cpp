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
