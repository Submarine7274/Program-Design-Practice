/* 要有
    string firstName
    string middleName
    string lastName
    Sex gender
    unsigned int yearOfBirth
    string registrationNumber
    string email
    可以自行決定datatype
    要有七個參數的建構子並初始化data member
    要提供get 跟 set function 給data member
    */
#include<string>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
class Student{
    public:
    enum class Sex{male,female};    //注意這個要寫在前面，不然會形成未定義
    Student(string newfirstName,string newmiddleName,string newlastName, Sex newgender, unsigned int newyearOfBirth,string newregistrationNumber,string newemail);
    void setFirstName(string);
    void setMiddleName(string);
    void setLastName(string);
    void setSex(Sex);
    void setYearOfBirth(unsigned int);
    void setRegistrationNumber(string);
    void setEmail(string);

    string getFirstName() const;
    string getMiddleName()const;
    string getLastName()const;
    Sex getSex()const;
    unsigned int getYearOfBirth()const;
    string getRegistrationNumber()const;
    string getEmail()const;

    string toString() const;

    private:
    string firstName;
    string middleName;
    string lastName;
    Sex gender;
    unsigned int yearOfBirth;
    string registrationNumber;
    string email;
};

#endif