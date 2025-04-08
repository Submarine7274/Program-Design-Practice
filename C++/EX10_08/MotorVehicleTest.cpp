#include "MotorVehicle.h"// for MotorVehicle
using namespace std;
int main() {
// instantiate two objects
MotorVehicle mv1("Toyota", "Gasolene", 2005, "White", 1500);
MotorVehicle mv2("Subaru", "Gasolene", 2001, "Pearl", 2000);
MotorVehicle mv3 = mv1;
// display vehicle details using overloaded << operator
cout << mv1;
cout << mv2;
cout << mv3;
// test overloaded operators:
// inequality
if (mv1 != mv2) {
cout<<"mv1 and mv2 are not equal.\n"<<endl;
} 
else {
cout<<"mv1 is equal to mv2.\n"<<endl;
}
// equality
if (mv1 == mv3) {
cout<<"mv1 and mv3 are equal.\n"<<endl;
}
else {
cout<<"mv1 and mv3 are not equal.\n"<<endl;
}
// greater than
if (mv1 > mv2) {
cout<<"mv1 is was manufactured after mv2.\n"<<endl;
}
else {
cout<<"mv1 was manufactured before mv2.\n"<<endl;
}
return 0;
}
