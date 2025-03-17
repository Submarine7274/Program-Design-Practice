#include<iostream>
#include<stdexcept>
#include<string>
#include<array>
#include<sstream>
#include"ImprovedStudent.h"

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
Date::Date(unsigned int m, unsigned int d, unsigned int y) 
   :year{y} {
        setMonth(m);
        setDay(d);
   }

// print Date in the format mm/dd/yyyy
string Date::toString() const {
   ostringstream output;
   output << month << '/' << day << '/' << year;
   return output.str();
}

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

unsigned int Date::getMonth(){
    return month;
}
unsigned int Date::getDay(){
    return day;
}
unsigned int Date::getYear(){
    return year;
}

bool Date::isLeapYear(unsigned int year){               //這個函式是為了確定是不是閏年
    if((year%4 ==0)&&(year%100!=0)||(year%400==0)){     //閏年是被4整除，但不被100整除，如果被400整除的話，也是閏年
        return true;
    }
    return false;
}
Name::Name(string newfirstName,string newmiddleName,string newlastName){
    setFirstName(newfirstName);
    setMiddleName(newmiddleName);
    setLastName(newlastName);
}
void Name::setFirstName(string newFirstName){
    firstName =newFirstName;
}
void Name::setMiddleName(string newmiddleName){
    middleName= newmiddleName;
}
void Name::setLastName(string newLastName){
    lastName =newLastName;
}
string Name::getFirstName()const{
    return firstName;
}
string Name::getMiddleName()const{
    return middleName;
}
string Name::getLastName()const{
    return lastName;
}
string Name::toString() const {      //toString 是const的話，get function 都要是const 
    ostringstream output;
    output << getFirstName()<<" "<<getMiddleName()<<" "<<getLastName();
    return output.str();
}

Student::Student(Name newName, Sex newgender,Date newBirthday,string newregistrationNumber,string newemail)
:studentName(newName),gender(newgender),birthDay(newBirthday),registrationNumber(newregistrationNumber),email(newemail)
{

}
void Student::setName(Name newName){
    studentName =newName;
}
void Student::setSex(Sex newSex){
    gender =newSex;
}
void Student::setBirthday(Date newBirthDay){
    birthDay = newBirthDay;
}
void Student::setRegistrationNumber(string newRegeistrationNumber){
    registrationNumber=newRegeistrationNumber;
}
void Student::setEmail(string newEmail){
    email =newEmail;
}
Student::Sex Student::getSex()const{     //注意enum class也是Student裡的東西，所以要用::，也就是說Sex前面要加Student::
    return gender;
}
Date Student::getBirthday()const{
    return birthDay;
}
Name Student::getName()const{
    return studentName;
}
string Student::getRegistrationNumber()const{
    return registrationNumber;
}
string Student::getEmail()const{
    return email;
}
string Student::toString() const {      //toString 是const的話，get function 都要是const 另外ostream不認得enum裡的東西，所以要寫判別式
    ostringstream output;
    output << "Name: " << studentName.toString() << "\n"
           << "Gender: " << (getSex() == Sex::male ? "Male" : "Female") << "\n"
           << "Birthday: " << birthDay.toString() << "\n"
           << "Registration Number: " << getRegistrationNumber() << "\n"
           << "Email: " << getEmail() << "\n";
    return output.str();
    /*這邊比較不一樣的地方是用變數名去呼叫他所屬class的function 像是studentName.toString()，以及birthDay.toString()*/
 }