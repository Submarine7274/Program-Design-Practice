/*修改課本的例子 增加一個tick member function來增加1秒*/
// Fig. 9.6: Time.cpp
// Member-function definitions for class Time.
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member    
Time::Time(int hour, int minute, int second) {
   setTime(hour, minute, second); // validate and set time
}

// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
   setHour(h); // set private field hour
   setMinute(m); // set private field minute
   setSecond(s); // set private field second
}

// set hour value
void Time::setHour(int h) {
   if (h >= 0 && h < 24) {
      hour = h;
   }
   else {
      throw invalid_argument("hour must be 0-23");
   }
}

// set minute value
void Time::setMinute(int m) {
   if (m >= 0 && m < 60) {
      minute = m;
   }
   else {
      throw invalid_argument("minute must be 0-59");
   }
}

// set second value
void Time::setSecond(int s) {
   if (s >= 0 && s < 60) {
      second = s;
   }
   else {
      throw invalid_argument("second must be 0-59");
   }
}

// return hour value
unsigned int Time::getHour() const { return hour; }

// return minute value
unsigned Time::getMinute() const { return minute; }

// return second value
unsigned Time::getSecond() const { return second; }

// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const {
   ostringstream output;
   output << setfill('0') << setw(2) << getHour() << ":"
      << setw(2) << getMinute() << ":" << setw(2) << getSecond();
   return output.str();
}

// return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const {
   ostringstream output;
   output << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
      << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
      << getSecond() << (hour < 12 ? " AM" : " PM");
   return output.str();
}
void Time::tick(){                                                      //題目要得function
    int sec =getSecond()+1;                                             //變數宣告,sec是物件的秒數+1
    int min = getMinute();                                              //min是物件的分鐘
    int hour =getHour();                                                //hour是物件的小時
    if(sec ==60){                                                       //如果到了60秒，要進位
        sec =0;                                                         //進位把sec設成零
        min++;                                                          //分鐘+1
    }
    if(min==60){                                                        //分鐘如果到了60分，要進位
        min =0;                                                         //進位把min設成零
        hour++;                                                         //小時+1
    }
    if(hour ==24){                                                      //小時如果到了24，要進位
        hour =0;                                                        //小時設成零
    }
    setSecond(sec);                                                     //最後把sec丟給setSecond函式
    setMinute(min);                                                     //把min丟給setMinute函式
    setHour(hour);                                                      //把hour丟給setHour函式
}
/*另一種寫法，程式效能比較高，但是比較不好讀，sec加1秒後取60餘數，進位會變成0，
min如果遇到sec進位(除以60等於1時)，一樣取60餘數
hour同理，看min有沒有進位，取24餘數，最後把時間set回去
void Time::tick(){
    int sec = (getSecond()+1)%60;
    int min = (getMinute()+((getSecond()+1)/60))%60;
    int hour = (getHour()+(getMinute()+((getSecond()+1)/60))/60)%24;
    setSecond(sec);
    setMinute(min);
    setHour(hour);
}
*/