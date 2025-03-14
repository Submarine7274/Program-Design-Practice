/*Date的測試程式*/ 
#include<iostream>
#include"Date.h"
using namespace std;

int main (void){
    Date dateObject{3,13,2024};

    cout<<"Month: "<<dateObject.getMonth()<<endl
    <<"Day: "<<dateObject.getDay()<<endl
    <<"Year: "<<dateObject.getYear()<<"\n"<<endl;   //cout串接輸出

    cout<<"Original date: ";                        //這邊要注意的是，我的displayDate()函示有cout，不可以再用cout串接
    dateObject.displayDate();
    cout<<"\n"<<endl;

    dateObject.setMonth(1);                         //測試各個set功能
    dateObject.setDay(31);
    dateObject.setYear(2025);

    cout<<"New date: ";                             //一樣，displayDate()函示有cout，不可以再用cout串接
    dateObject.displayDate();

    return 0;
}