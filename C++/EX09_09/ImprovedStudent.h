/* 用composition來改進，composition簡單說就是class裡面含有別的class的東西
這樣的好處是重複的東西可以多次利用，比方說名字
如果要同時宣告teacher class、student class、officer class
我就不需要在每個class裡面需要用超多name function 跟data member
只要用一個name class就可以在多個class裡使用
題目要用Name class把三個data member包起來
用之前的Date Class把yearOfBirth變成完整的生日
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
class Name{         //新增一個Name class 把原本Student裡面跟名字有關的data member 跟member function都拿來這邊
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
        /*這邊建構子傳入的參數，名字就用Name class，生日用 Date class，之後會學用&refernce的方法，pass by value會複製一整個class的值，之後不會這樣寫
        會寫成
        Student(const Name& newname, Sex newgender,const Date& newBirthDay,string newregistrationNumber,string newemail);
        pass by reference直接傳記憶體位址，同時避免改到輸入的值(因為是const)
        */
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
        Name studentName;           //Name class的變數studentName
        Sex gender;                 //Sex class的變數gender
        Date birthDay;              //Date class的變數birthday
        string registrationNumber;
        string email;
};

#endif