/*測試程式要用迴圈測試tick function有沒有正常運作 要能進位到分鐘 分鐘也要能進位到小時 小時也要進位到下一天*/
// Fig. 9.7: fig09_07.cpp 
// Constructor with default arguments.
#include <iostream>
#include <stdexcept>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// displays a Time in 24-hour and 12-hour formats
void displayTime(const string& message, const Time& time) {
   cout << message << "\nUniversal time: " << time.toUniversalString()
      << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {
   /*Time t1; // all arguments defaulted                              
   Time t2{2}; // hour specified; minute and second defaulted     
   Time t3{21, 34}; // hour and minute specified; second defaulted
   Time t4{12, 25, 42}; // hour, minute and second specified      

   cout << "Constructed with:\n\n";
   displayTime("t1: all arguments defaulted", t1);
   displayTime("t2: hour specified; minute and second defaulted", t2);
   displayTime("t3: hour and minute specified; second defaulted", t3);
   displayTime("t4: hour, minute and second specified", t4);

   // attempt to initialize t5 with invalid values
   try {
      Time t5{27, 74, 99}; // all bad values specified
   }
   catch (invalid_argument& e) {
      cerr << "Exception while initializing t5: " << e.what() << endl;
   }*/
  Time timeobject1{23,0,0};                                       //前面東西就不測了，直接測tick，用23時來測到隔天
  for(int i=0; i<3600;i++){                                       //跑個1小時的秒數
    timeobject1.tick();                                           //呼叫函式
    cout<<"Current time: "<<timeobject1.toStandardString()<<endl; //輸出每一次呼叫函式後的時間(12小時制)
  }
  return 0;
}
