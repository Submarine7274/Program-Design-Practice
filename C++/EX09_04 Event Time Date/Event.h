#include <string>
#ifndef EVENT_H
#define ENENT_H
using namespace std;
class Date{
    public:
        explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2025);
        std::string toString() const;
    
        void setMonth(unsigned int);
        void setDay(unsigned int);
        void setYear(unsigned int);
    
        unsigned int getMonth();
        unsigned int getDay();
        unsigned int getYear();
    private:
        unsigned int month{1};
        unsigned int day{1};
        unsigned int year{2025};
        bool isLeapYear(unsigned int);   //等等要用到的閏年檢查 
};
class Time{
    public:
        explicit Time(int = 0, int = 0, int = 0); // default constructor
        void setTime(int, int, int); 
        void setHour(int); 
        void setMinute(int); 
        void setSecond(int);
    
        // get functions
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
class Event{
    public:
        Event(Date,Time);
        void setEventDate(Date);
        Date getEventDate();
        void setEventTime(Time);
        Time getEventTime();
    private:
        Date eventDay;
        Time enentTime;
};

#endif