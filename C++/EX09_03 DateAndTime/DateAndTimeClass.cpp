/*如果tick()會進入下一天的話，要呼叫nextDay()
    要能印出12小時制跟24小時制
*/
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<stdexcept>
#include<array>
#include"DateAndTime.h"
using namespace std;
static const array<int,13>daysPerMonth{
    0,31,28,31,30,31,30,31,31,30,31,30,31
};
DateAndTime::DateAndTime(unsigned int newmonth,unsigned int newday, unsigned int newyear, unsigned int newhour, unsigned int newminute, unsigned int newsecond){
    setYear(newyear);
    setMonth(newmonth);
    setDay(newday);
    setHour(newhour);
    setMinute(newminute);
    setSecond(newsecond);
}
unsigned int DateAndTime:: getYear() const{
    return year;
}
unsigned int DateAndTime:: getMonth() const{
    return month;
}
unsigned int DateAndTime:: getDay() const{
    return day;
}
unsigned int DateAndTime:: getHour() const{
    return hour;
}
unsigned int DateAndTime:: getMinute() const{
    return minute;
}
unsigned int DateAndTime:: getSecond() const{
    return second;
}
void DateAndTime:: setYear(unsigned int newyear){
    if(newyear==0){
        throw invalid_argument("Year must greater than 0.");
    }
    year = newyear;
}
void DateAndTime:: setMonth(unsigned int newmonth){
    if(newmonth==0||newmonth>12){
        throw invalid_argument("Month should be 1~12.");
    }
    month = newmonth;
}
void DateAndTime:: setDay(unsigned int newday){
    unsigned int daysCurrentMonth = (getMonth()==2&&(isLeapYear(getYear())))?29:daysPerMonth[getMonth()];
    if(newday ==0||newday>daysCurrentMonth){
        throw invalid_argument("Day out of range.");
    }
    day =newday;
}
void DateAndTime::setHour(unsigned int newhour){
    if(newhour >23){
        throw invalid_argument("Hour must be 0-23");
    }
    hour =newhour;
}
void DateAndTime::setMinute(unsigned int newminute){
    if(newminute >59){
        throw invalid_argument("Minute must be 0-59.");
    }
    minute =newminute;
}
void DateAndTime::setSecond(unsigned int newsecond){
    if(newsecond >59){
        throw invalid_argument("Second must be 0-59.");
    }
    second =newsecond;
}
bool DateAndTime:: isLeapYear(unsigned int newyear){
    if((newyear%4==0)&&(newyear%100!=0)||(newyear%400==0)){
        return true;
    }
    return false;
}
void DateAndTime:: nextDay(){
    unsigned int newday = getDay()+1;                   //原本的日期+1
    unsigned int newmonth = getMonth();                 //原本的月份
    unsigned int newyear = getYear();                   //原本的年
    unsigned int daysCurrentMonth = (newmonth==2&&isLeapYear(newyear))?29:daysPerMonth[newmonth];
    /*宣告一個變數daysCurrentMonth 來表示這個月有幾天，
    如果是2月並且是閏年的話，29天，如果是其他的，就用daysPerMonth陣列，並用newmonth來索引是幾月
    */
    if(newday > daysCurrentMonth){                      //如果新的日超過該月天數
        newday=1;                                       //日設成1
        newmonth++;                                     //月份+1
    }
    if(newmonth >12){                                   //如果月份超過12
        newmonth =1;                                    //月設成1
        newyear++;                                      //年+1
    }
    setDay(newday);                                     //最後再把變數傳回去set Function裡
    setMonth(newmonth);
    setYear(newyear);
}

/*
宣告一個bool叫做nextDayFlag，如果當下是23:59:59，那下一秒就是隔天，呼叫nextDay()
sec加1秒後取60餘數，進位會變成0，
min如果遇到sec進位(除以60等於1時)，一樣取60餘數
hour同理，看min有沒有進位，取24餘數，最後把時間set回去*/
void DateAndTime::tick(){
    bool nextDayFlag=((getHour()==23)&&(getMinute()==59)&&(getSecond()==59));
    int sec = (getSecond()+1)%60;
    int min = (getMinute()+((getSecond()+1)/60))%60;
    int hour = (getHour()+(getMinute()+((getSecond()+1)/60))/60)%24;
    setSecond(sec);
    setMinute(min);
    setHour(hour);
    if(nextDayFlag){
        nextDay();
    }
}
string DateAndTime::toUniversalString() const {
    ostringstream output;
    output<<getMonth() << '/' << getDay() << '/' << getYear()<<' ' << setfill('0') << setw(2) << getHour() << ":"
       << setw(2) << getMinute() << ":" << setw(2) << getSecond()<<endl;
    return output.str();
}
string DateAndTime::toStandardString() const {
    ostringstream output;
    output <<getMonth() << '/' << getDay() << '/' << getYear()<<' '  << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
       << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
       << getSecond() << (hour < 12 ? " AM" : " PM")<<endl;
    return output.str();
 }