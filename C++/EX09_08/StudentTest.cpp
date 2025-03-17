/*Student class的測試程式*/
#include<iostream>
#include<string>
#include"Student.h"
using namespace std;

int main (void){
    Student object1{"Grace","Eleanor","Snow",Student::Sex::female,1990,"ACS112","acs112@gm.ntcu.edu.tw"};
    /*enum class 的建構比較麻煩class名::enum class名::裡面的值*/
    cout<<object1.toString()<<endl;
    return 0;
}