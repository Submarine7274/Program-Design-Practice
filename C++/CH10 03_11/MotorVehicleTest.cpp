#include "MotorVehicle.h"  // for MotorVehicle
using namespace std;
int main() {
  // instantiate two objects
  MotorVehicle mv1("Toyota", "Gasolene", 2005, "White", 1500);
  MotorVehicle mv2("Subaru", "Gasolene", 2001, "Pearl", 2000);
  // display vehicle details
  mv1.displayCarDetails();
  mv2.displayCarDetails();
  // change year of manufacture for mv1
  mv1.setYearOfManufacture(2008);
  // change color for mv2
  mv2.setColor("Blue");
  // display values for updated objects
  mv1.displayCarDetails();
  mv2.displayCarDetails();
}
