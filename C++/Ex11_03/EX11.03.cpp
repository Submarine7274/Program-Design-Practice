// 題目要求我們把繼承的class 用Composition(組合)的方式重寫
// 也就是BasePlusCommissionEmployee裡面有CommissionEmployee的東西
// 為了方便我把兩個class寫在一起
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "EX11.03.h"
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
   const string& first, const string& last, const string& ssn,
   double sales, double rate, double salary)
   :employee(first,last,ssn,sales,rate){        //因為是組合，所以是用內部物件做初始化
   setBaseSalary(salary); 
}

// set first name
void BasePlusCommissionEmployee::setFirstName(const string& first) {
   employee.setFirstName(first); //這邊用CommissionEmployee的employee物件來setFirstName，稱為委派
}

// return first name
string BasePlusCommissionEmployee::getFirstName() const {
   return employee.getFirstName();//這邊用CommissionEmployee的employee物件來調用CommissionEmployee的函式
}

// set last name
void BasePlusCommissionEmployee::setLastName(const string& last) {
   employee.setLastName(last);      //這邊也是用別的class的函式
}

// return last name
string BasePlusCommissionEmployee::getLastName() const { 
    return employee.getLastName();      //這邊也是用別的class的函式
}

// set social security number
void BasePlusCommissionEmployee::setSocialSecurityNumber(
   const string& ssn) {
   employee.setSocialSecurityNumber(ssn);       //這邊也是用別的class的函式
}

// return social security number
string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
   return employee.getSocialSecurityNumber();       //這邊也是用別的class的函式
}

// set gross sales amount
void BasePlusCommissionEmployee::setGrossSales(double sales) {
   if (sales < 0.0) {
      throw invalid_argument("Gross sales must be >= 0.0");
   }

   employee.setGrossSales(sales);       //這邊也是用別的class的函式
}

// return gross sales amount
double BasePlusCommissionEmployee::getGrossSales() const {
   return employee.getGrossSales();     //這邊也是用別的class的函式
}

// set commission rate
void BasePlusCommissionEmployee::setCommissionRate(double rate) {
   if (rate <= 0.0 || rate >= 1.0) {
      throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
   }

   employee.setCommissionRate(rate);        //這邊也是用別的class的函式
}

// return commission rate
double BasePlusCommissionEmployee::getCommissionRate() const {
   return employee.getCommissionRate();     //這邊也是用別的class的函式
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
   return baseSalary + employee.earnings();       //這邊也是用別的class的函式
}

// return string representation of BasePlusCommissionEmployee object     
string BasePlusCommissionEmployee::toString() const {
   ostringstream output;
   output << fixed << setprecision(2); // two digits of precision   
   output << "base-salaried commission employee: " << employee.getFirstName() << ' '
      << employee.getLastName() << "\nsocial security number: " << employee.getSocialSecurityNumber()
      << "\ngross sales: " << employee.getGrossSales()
      << "\ncommission rate: " << employee.getCommissionRate()
      << "\nbase salary: " << baseSalary;
   return output.str();
}

//下面是CommissionEmployee這個class的實作，基本上就是複製過來，沒有動

CommissionEmployee::CommissionEmployee(const string& first,
    const string& last, const string& ssn, double sales, double rate) {
    firstName = first; // should validate                              
    lastName = last; // should validate                                
    socialSecurityNumber = ssn; // should validate                     
    setGrossSales(sales); // validate and store gross sales            
    setCommissionRate(rate); // validate and store commission rate     
 }
 
 // set first name
 void CommissionEmployee::setFirstName(const string& first) {
    firstName = first; // should validate
 }
 
 // return first name
 string CommissionEmployee::getFirstName() const { return firstName; }
 
 // set last name
 void CommissionEmployee::setLastName(const string& last) {
    lastName = last; // should validate
 }
 
 // return last name
 string CommissionEmployee::getLastName() const { return lastName; }
 
 // set social security number
 void CommissionEmployee::setSocialSecurityNumber(const string& ssn) {
    socialSecurityNumber = ssn; // should validate
 }
 
 // return social security number
 string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
 }
 
 // set gross sales amount
 void CommissionEmployee::setGrossSales(double sales) {
    if (sales < 0.0) {
       throw invalid_argument("Gross sales must be >= 0.0");
    }
 
    grossSales = sales;
 }
 
 // return gross sales amount
 double CommissionEmployee::getGrossSales() const { return grossSales; }
 
 // set commission rate
 void CommissionEmployee::setCommissionRate(double rate) {
    if (rate <= 0.0 || rate >= 1.0) {
       throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
    }
 
    commissionRate = rate;
 }
 
 // return commission rate
 double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
 }
 
 // calculate earnings                        
 double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
 }
 
 // return string representation of CommissionEmployee object        
 string CommissionEmployee::toString() const {
    ostringstream output;
    output << fixed << setprecision(2); // two digits of precision   
    output << "commission employee: " << firstName << " " << lastName
       << "\nsocial security number: " << socialSecurityNumber
       << "\ngross sales: " << grossSales
       << "\ncommission rate: " << commissionRate;
    return output.str();
 }