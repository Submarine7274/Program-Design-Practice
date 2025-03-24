#include<iostream>
#include<string>
#include"Time.h"
#include"Date.h"
#include"Event.h"

int main (void){
    Event object1{"New Year celebration",Date{1,1,2025},Time{8,0,0}};
    cout<<object1.toString();
    return 0;
}