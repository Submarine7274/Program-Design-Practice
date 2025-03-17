#include<iostream>
#include<string>
#include"ImprovedStudent.h"
int main (void){
    Student student1{Name{"Grace", "M", "Strongburg"}, Student::Sex::female, Date{1, 15, 1990}, "ACS112", "ACS112@gm.ntcu.edu.tw"};  //測試建構子 Sex是student class裡的enum class
    cout<<student1.toString()<<endl;                                                                        //測試整串輸出
    return 0;
}