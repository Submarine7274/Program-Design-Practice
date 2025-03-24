#include<string>
#ifndef TIME_H
#define TIME_H

class Time{
    public:
        explicit Time(int = 0, int = 0, int = 0); // default constructor
        void setTime(const Time&);                //這個是方便外部傳入的overloading寫法
        void setTime(int, int, int);              
        void setHour(int); 
        void setMinute(int); 
        void setSecond(int);
    
        unsigned int getHour() const; 
        unsigned int getMinute() const; 
        unsigned int getSecond() const; 
    
        std::string toUniversalString() const; // 24-hour time format string
        std::string toStandardString() const; // 12-hour time format string 
    private:
        unsigned int hour{0}; // 0 - 23 (24-hour clock format)
        unsigned int minute{0}; // 0 - 59
        unsigned int second{0}; // 0 - 59
};

#endif