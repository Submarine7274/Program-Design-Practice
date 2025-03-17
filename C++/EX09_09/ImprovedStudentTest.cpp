#include<iostream>
#include<string>
#include"ImprovedStudent.h"
int main (void){
    Name studentname1{"Grace","M","Strongburg"};
    Date studentbirthday1{1,15,1990};
    Student student1{studentname1,Student::Sex::female,studentbirthday1,"ACS112","ACS112@gm.ntcu.edu.tw"};
    cout<<student1.toString()<<endl;
    return 0;
}