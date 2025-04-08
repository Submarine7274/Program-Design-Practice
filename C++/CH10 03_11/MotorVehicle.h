#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
#include <string>    // for string
#include <iostream>  // for cout
class MotorVehicle {
public:
  MotorVehicle(std::string mk, std::string ft, int yom, std::string cl, int ecp);
  void setMake(std::string mk);
  void setFuelType(std::string ft);
  void setYearOfManufacture(int yom);
  void setColor(std::string cl);
  void setEngineCapacity(int ecp);
  std::string getMake();
  std::string getFuelType();
  int getYearOfManufacture();
  std::string getColor();
  int getEngineCapacity();
  void displayCarDetails();
private:
  std::string make;
  std::string fuelType;
  int yearOfManufacture;
  std::string color;
  int engineCapacity;
};
#endif