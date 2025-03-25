#include <sstream>
#include <string>
#include<stdexcept>
#include<array>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;
/* #include<array>  
    array語法:
    array<型別,大小>陣列名{元素1,元素2,}
*/ 
static const array<int ,13>daysPerMonth{    
    0,31,28,31,30,31,30,31,31,30,31,30,31
};
/*解釋一下這個陣列
    static 是為了限定作用域在這個檔案
    const是為了避免更動到裡面的值
    為甚麼是13是因為array的索引值都是從0開始
    我直接把0的位置用0，這樣可以直接傳入月份
    0是拿來佔位的
*/
// Date constructor (should do range checking)，這邊我把:後的初始化只留下year，其他傳入的月跟日要做資料驗證
Date::Date(unsigned int m, unsigned int d, unsigned int y){
    setMonth(m);
    setDay(d);
    setYear(y);
}
void Date::setDate(const Date& newdate){
    setDay(newdate.getDay());
    setMonth(newdate.getMonth());
    setYear(newdate.getYear());
}

// print Date in the format mm/dd/yyyy
string Date::toString() const {
   ostringstream output;
   output << month << '/' << day << '/' << year;
   return output.str();
}

/*因為課本範例沒有提供get跟set 這邊都要自己寫*/

void Date::setMonth(unsigned int newmonth){     //set月份，順便做資料檢查
    if(newmonth<1 ||newmonth >12){              //如果傳入的月份小於1或大於12，都送出exception
        throw invalid_argument(
            "Month should be 1~12."
        );
    }
    month =newmonth;                            //沒送出exception，就把傳入的月份賦值給month
}

void Date::setDay(unsigned int newday){
    unsigned int daysCurrentMonth = (getMonth()==2&&isLeapYear(getYear()))?29:daysPerMonth[getMonth()];
    /*宣告一個變數daysCurrentMonth 來決定本月有幾天
        這邊用到條件的三元運算子，語法如下:
        (條件) ? true執行這邊 : false執行這邊
        這邊的條件是月份是2且是閏年
        true的話daysCurrentMonth變數用29賦值
        false的話用上面的陣列daysPerMonth[月份]
    */
    if(newday<1 ||newday >daysCurrentMonth){    //如果日小於1或者大於本月天數，就送exception
        throw invalid_argument(
            "Day out of range."
        );
    }
    day =newday;                                //沒送出exception，就把傳入的日賦值給day
}

void Date::setYear(unsigned int newyear){       //年就比較簡單了，傳入限定是正數
    if(newyear ==0 ){                           //等於0就送exception
        throw invalid_argument(
            "Year should not be less than 1."
        );
    }
    year =newyear;                              //沒送出exception，就把傳入的年賦值給year
}

unsigned int Date::getMonth() const{                  //這邊是get function
    return month;
}
unsigned int Date::getDay() const{
    return day;
}
unsigned int Date::getYear() const{
    return year;
}

bool Date::isLeapYear(unsigned int year){               //這個函式是為了確定是不是閏年
    if((year%4 ==0)&&(year%100!=0)||(year%400==0)){     //閏年是被4整除，但不被100整除，如果被400整除的話，也是閏年
        return true;
    }
    return false;
}