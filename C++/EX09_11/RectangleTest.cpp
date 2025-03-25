#include<iostream>
#include<stdexcept>
#include"Rectangle.h"
using namespace std;

int main(void){
    try{
        Rectangle object1;
        cout<<"The default length is: "<<object1.getLength()<<endl;
        cout<<"The default width is: "<<object1.getWidth()<<endl;
        cout<<"Set new width 5.0, new length 10.0"<<endl;
        object1.setWidth(5.0);
        object1.setLength(10.0);
        cout<<"New length is: "<<object1.getLength()<<endl;
        cout<<"New width is: "<<object1.getWidth()<<endl;
        cout<<"Perimeter is: "<<object1.perimeter()<<endl;
        cout<<"Area is: "<<object1.area()<<endl;

        //測試錯誤情境
        cout<<"Try to set length to 21.0"<<endl;
        object1.setLength(21.0);
    }catch(const exception &e){
        cerr<<e.what()<<endl;
    }
    return 0;
}