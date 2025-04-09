/*題目要求我們把繼承的class 用Composition(組合)的方式重寫
也就是BasePlusCommissionEmployee裡面有CommissionEmployee的東西
為了方便我把兩個class寫在一起
*/
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ standard string class
using namespace std;

class CommissionEmployee {
    public:
       CommissionEmployee(const std::string&, const std::string&,
          const std::string&, double = 0.0, double = 0.0);
    
       void setFirstName(const std::string&); // set first name
       std::string getFirstName() const; // return first name
    
       void setLastName(const std::string&); // set last name
       std::string getLastName() const; // return last name
    
       void setSocialSecurityNumber(const std::string&); // set SSN
       std::string getSocialSecurityNumber() const; // return SSN
    
       void setGrossSales(double); // set gross sales amount
       double getGrossSales() const; // return gross sales amount
    
       void setCommissionRate(double); // set commission rate (percentage)
       double getCommissionRate() const; // return commission rate
    
       double earnings() const; // calculate earnings
       std::string toString() const; // create string representation
    private:
       std::string firstName;
       std::string lastName;
       std::string socialSecurityNumber;
       double grossSales; // gross weekly sales
       double commissionRate; // commission percentage
    };

class BasePlusCommissionEmployee {
public:
    BasePlusCommissionEmployee(const std::string&, const std::string&, 
    const std::string&, double = 0.0, double = 0.0, double = 0.0);
   
    void setFirstName(const std::string&);
    std::string getFirstName() const;

    void setLastName(const std::string&);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string&);
    std::string getSocialSecurityNumber() const;

    void setGrossSales(double);
    double getGrossSales() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    std::string toString() const;
private:
   CommissionEmployee employee;     //這邊用CommissionEmployee這個class的物件，因為題目要求用composition
   double baseSalary; // base salary
};

#endif

