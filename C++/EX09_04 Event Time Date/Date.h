#include <string>

// prevent multiple inclusions of header
#ifndef DATE_H
#define DATE_H

// class Date definition
class Date{
    public:
        explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2025);
        std::string toString() const;
        void setDate(const Date&);                                              //方便外面傳入的setDate函式
        void setMonth(unsigned int);
        void setDay(unsigned int);
        void setYear(unsigned int);
    
        unsigned int getMonth() const;
        unsigned int getDay() const;
        unsigned int getYear() const;
    private:
        unsigned int month{1};
        unsigned int day{1};
        unsigned int year{2025};
        bool isLeapYear(unsigned int);   //等等要用到的閏年檢查 
};

#endif