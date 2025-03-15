// Fig. 9.16: fig09_16.cpp 
// Demonstrating that class objects can be assigned
// to each other using default memberwise assignment.
#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

int main() {
//    Date date1{7, 4, 2004};
//    Date date2; // date2 defaults to 1/1/2000

//    cout << "date1 = " << date1.toString()
//       << "\ndate2 = " << date2.toString() << "\n\n";

//    date2 = date1; // default memberwise assignment

//    cout << "After default memberwise assignment, date2 = "
//       << date2.toString() << endl;

    /*前面就不測了，直接測nextDay()函式 */
    Date date1{12,1,2025}; 
    Date date2{2,1,2024};
    cout<<"From 12/1/2025 to 1/1/2026: "<<endl;             //從12月1日2025年開始
    for(int i=0; i<31; i++){                                //執行31次
        date1.nextDay();                                    //呼叫nextDay函式
        cout<<date1.toString()<<endl;                       //輸出每次的結果
    }

    cout<<"From 2/1/2024 to 3/1/2024: "<<endl;              //從2月1日2024年開始
    for(int i=0; i<29; i++){                                //執行29次，測試閏年
        date2.nextDay();                                    //呼叫nextDay函式
        cout<<date2.toString()<<endl;                       //輸出每次的結果
    }

    return 0;
}