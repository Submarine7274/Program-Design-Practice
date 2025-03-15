/*修改class Date要有初始值的檢查
    提供一個nextDay()fuuction來增加一天
    日期要維持合理日期
*/
// Fig. 9.14: Date.h
// Date class declaration.  Member functions are defined in Date.cpp.
#include <string>

// prevent multiple inclusions of header
#ifndef DATE_H
#define DATE_H

// class Date definition
class Date {
public:
   explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 2000);
   std::string toString() const;

   /*範例沒寫set 跟 get 的function 所以要先寫 */
   void setMonth(unsigned int);
   void setDay(unsigned int);
   void setYear(unsigned int);

   unsigned int getMonth();
   unsigned int getDay();
   unsigned int getYear();

   
   bool isLeapYear(unsigned int);   //等等要用到的閏年檢查
   void nextDay();                  //題目要的nextDay function


private:
   unsigned int month;
   unsigned int day;
   unsigned int year;
};

#endif