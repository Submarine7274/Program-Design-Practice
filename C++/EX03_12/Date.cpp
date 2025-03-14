/*三個data member, int month, int day, int year
要有一個constructor接受三個參數輸入並初始化三個data member
直接假設年跟日期是正確的，但要確保月份是1~12，如果不是12的話，將月份設為1
每個data member都要有get 跟 set function
提供一個displayDate()的member function 來顯示日月年 用/隔開
*/

#include <iostream>
#include"Date.h"
using namespace std;

    Date::Date(int newmonth, int newday, int newyear){
        setMonth(newmonth);
        setDay(newday);
        setYear(newyear);
    }

    void Date::setMonth(int newmonth){
        if(newmonth >=1&&newmonth<=12){
            month =newmonth;
        }
        else{
            month =1;
        }
    }
    int Date::getMonth(){
        return month;
    }

    void Date::setDay(int newday){
        if(newday>=1&&newday<=31){
            day=newday;
        }
        else{
            day=1;
        }
    }
    int Date::getDay(){
        return day;
    }

    void Date::setYear(int newyear){
        if(newyear>0){
            year =newyear;
        }
        else{
            year=1;
        }
    }
    int Date::getYear(){
        return year;
    }

    void Date::displayDate(){
        cout<<getMonth()<<"/"<<getDay()<<"/"<<getYear();
    }