/* 用composition來改進
用Name class把三個data member包起來
用Date Class把yearOfBirth變成完整的生日
    */
#include<string>
#ifndef IMPROVEDSTUDENT_H
#define IMPROVEDSTUDENT_H
using namespace std;

class Date {                                                                    //把之前的Date拿過來用
    public:
       explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2000);
       string toString() const;
       void setMonth(unsigned int);
       void setDay(unsigned int);
       void setYear(unsigned int);   
       unsigned int getMonth();
       unsigned int getDay();
       unsigned int getYear();       
       bool isLeapYear(unsigned int);  
    private:
       unsigned int month;
       unsigned int day;
       unsigned int year;
};
class Name{         //新增一個Name class 把原本Student裡面跟名字有關的data member 跟member function都拿來
    public:
        Name(string newfirstName,string newmiddleName,string newlastName);
        string getFirstName() const;
        string getMiddleName()const;
        string getLastName()const;
        void setFirstName(string);
        void setMiddleName(string);
        void setLastName(string);
        string toString()const;
    private:
        string firstName;
        string middleName;
        string lastName;
};
class Student{
    public:
        enum class Sex{male,female};    //注意這個要寫在前面，不然會形成未定義
        Student(Name newname, Sex newgender,Date newBirthDay,string newregistrationNumber,string newemail);
        /*這邊建構子傳入的參數，名字就用Name class，生日用 Date class*/
        void setSex(Sex);
        void setBirthday(Date);
        void setName(Name);
        void setRegistrationNumber(string);
        void setEmail(string);

        Sex getSex()const;
        Date getBirthday()const;
        Name getName()const;
        string getRegistrationNumber()const;
        string getEmail()const;
        string toString() const;

    private:
        Name studentName;
        Sex gender;
        Date birthDay;
        string registrationNumber;
        string email;
};

#endif