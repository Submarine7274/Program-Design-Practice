#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
#include <string>
#include <iostream>
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
// overloaded relational operators
bool operator==(const MotorVehicle& mv) const;
bool operator!=(const MotorVehicle& mv) const;
bool operator>(const MotorVehicle& mv) const;
friend std::ostream& operator<<(std::ostream& out, const MotorVehicle& mv);
private:
std::string make;
std::string fuelType;
int yearOfManufacture;
std::string color;
int engineCapacity;
};
#endif