//函式原型及data member
#ifndef DATA_H
#define DATA_H
class Date{
public:
    Date(int newmonth, int newday, int newyear);

    void setMonth(int newmonth);
    int getMonth();

    void setDay(int newday);
    int getDay();

    void setYear(int newyear);
    int getYear();

    void displayDate();


private:
    int month{1};
    int day{1};
    int year{1};
};
#endif
