// Member-function definitions of class BasePlusCommissionEmployee 
// using composition.
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "CommissionEmployee.h"
// BasePlusCommissionEmployee class definition
#include "BasePlusCommissionEmployee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
   const string& first, const string& last, const string& ssn,
   double sales, double rate, double salary): commissionEmployee(first, last, ssn, sales, rate) 
{
 setBaseSalary(salary);
}

// set first name
void BasePlusCommissionEmployee::setFirstName(const string &first) {
   commissionEmployee.setFirstName(first);
}

// return first name
string BasePlusCommissionEmployee::getFirstName() const {
   return commissionEmployee.getFirstName();
}

// set last name
void BasePlusCommissionEmployee::setLastName(const string& last) {
   commissionEmployee.setLastName(last);
}

// return last name
string BasePlusCommissionEmployee::getLastName() const {
   return commissionEmployee.getLastName();
}

// set social security number
void BasePlusCommissionEmployee::setSocialSecurityNumber(const string &ssn) {
   commissionEmployee.setSocialSecurityNumber(ssn);
}

// return social security number
string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
   return commissionEmployee.getSocialSecurityNumber();
}

// set gross sales amount
void BasePlusCommissionEmployee::setGrossSales(double sales) {
   if (sales < 0.0) {
      throw invalid_argument("Gross sales must be >= 0.0");
   }

   commissionEmployee.setGrossSales(sales);
}

// return gross sales amount
double BasePlusCommissionEmployee::getGrossSales() const {
   return commissionEmployee.getGrossSales();
}

// set commission rate
void BasePlusCommissionEmployee::setCommissionRate(double rate) {
   if (rate <= 0.0 || rate >= 1.0) {
      throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
   }

   commissionRate = rate;
}

// return commission rate
double BasePlusCommissionEmployee::getCommissionRate() const {
   return commissionRate;
}

// set base salary                                             
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
   if (salary < 0.0) {
      throw invalid_argument("Salary must be >= 0.0");
   }

   baseSalary = salary;
}

// return base salary                                     
double BasePlusCommissionEmployee::getBaseSalary() const {
   return baseSalary;
}

// calculate earnings                                
double BasePlusCommissionEmployee::earnings() const {
   return getBaseSalary() + commissionEmployee.earnings();
}

// return string representation of BasePlusCommissionEmployee object     
string BasePlusCommissionEmployee::toString() const {
   ostringstream output;
   output << fixed << setprecision(2); // two digits of precision   
   output << "base-salaried commission employee: " << firstName << ' '
      << lastName << "\nsocial security number: " << socialSecurityNumber
      << "\ngross sales: " << grossSales
      << "\ncommission rate: " << commissionRate
      << "\nbase salary: " << baseSalary;
   return output.str();
}
 void BasePlusCommissionEmployee::print() const
	{
		cout << "base-salaried ";
		
		commissionEmployee.print();
		
		cout << "\nbase salry: " << getBaseSalary();
	}