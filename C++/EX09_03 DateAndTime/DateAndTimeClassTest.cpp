/*測試DateAndTime class的程式 特別要測是不是能正確進入下一天*/
#include<iostream>
#include"DateAndTime.h"
using namespace std;
int main (void){
    //DateAndTime object1{13,32,0,24,60,60}; 測試有沒有報錯
    DateAndTime object2{12,31,2024,23,59,59};    //宣告一個跨年變數
    DateAndTime object3{2,28,2024,23,59,59};     //宣告一個閏年變數

    cout<<"Current Time: \n"<<object2.toStandardString()<<object2.toUniversalString();
    object2.tick();
    cout<<"Current Time after 1 tick: \n"<<object2.toStandardString()<<object2.toUniversalString();

    cout<<"Current Time: \n"<<object3.toStandardString()<<object3.toUniversalString();
    object3.tick();
    cout<<"Current Time after 1 tick: \n"<<object3.toStandardString()<<object3.toUniversalString();
    return 0;
}