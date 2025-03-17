/* 把Date跟Time兩個class組合起來成一個class */
#include<string>
#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime{
    public:
    explicit DateAndTime(unsigned int newmonth=1,unsigned int newday=1, unsigned int newyear=1, unsigned int newhour=0, unsigned int newminute=0, unsigned int newsecond=0);

    void setMonth(unsigned int);
    void setDay(unsigned int);
    void setYear(unsigned int);
    void setHour(unsigned int);
    void setMinute(unsigned int);
    void setSecond(unsigned int);

    unsigned int getMonth() const;
    unsigned int getDay() const;
    unsigned int getYear() const;
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    bool isLeapYear(unsigned int);   //等等要用到的閏年檢查
    void nextDay();                  //題目要的nextDay function
    void tick();

    std::string toUniversalString() const; // 24-hour time format string
    std::string toStandardString() const; // 12-hour time format string
 

    private:
    unsigned int year{2025};
    unsigned int month{1};
    unsigned int day{1};
    unsigned int hour{0};
    unsigned int minute{0};
    unsigned int second{0};
};

#endif