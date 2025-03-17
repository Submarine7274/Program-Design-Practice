
#include"Student.h"
#include<string>
#include<stdexcept>
#include<sstream>
using namespace std;

Student::Student(string newfirstName,string newmiddleName,string newlastName, Sex newgender, unsigned int newyearOfBirth,string newregistrationNumber,string newemail)
:firstName(newfirstName),middleName(newmiddleName),lastName(newlastName),gender(newgender),registrationNumber(newregistrationNumber),email(newemail)
{
    setYearOfBirth(newyearOfBirth);
}
void Student::setFirstName(string newFirstName){
    firstName =newFirstName;
}
void Student::setMiddleName(string newmiddleName){
    middleName= newmiddleName;
}
void Student::setLastName(string newLastName){
    lastName =newLastName;
}
void Student::setSex(Sex newSex){
    gender =newSex;
}
void Student::setYearOfBirth(unsigned int newYearOfbirth){
    if(newYearOfbirth ==0){
        throw invalid_argument("Year of birth should greater than 0.");
    }
    yearOfBirth=newYearOfbirth;
}
void Student::setRegistrationNumber(string newRegeistrationNumber){
    registrationNumber=newRegeistrationNumber;
}
void Student::setEmail(string newEmail){
    email =newEmail;
}

string Student::getFirstName()const{
    return firstName;
}
string Student::getMiddleName()const{
    return middleName;
}
string Student::getLastName()const{
    return lastName;
}
Student::Sex Student::getSex()const{     //注意enum class也是Student裡的東西，所以要用::，也就是說Sex前面要加Student::
    return gender;
}
unsigned int Student::getYearOfBirth()const{
    return yearOfBirth;
}
string Student::getRegistrationNumber()const{
    return registrationNumber;
}
string Student::getEmail()const{
    return email;
}
string Student::toString() const {      //toString 是const的話，get function 都要是const 另外ostream不認得enum裡的東西，所以要寫判別式
    ostringstream output;
    output << getFirstName()<<" "<<getMiddleName()<<" "<<getLastName()<<" "<<(getSex() ==Sex::male?"male":"female")<<" "<<getYearOfBirth()<<" "<<getRegistrationNumber()<<" "<<getEmail()<<"\n";
    return output.str();
 }