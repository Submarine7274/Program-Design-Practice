#include<iostream>
#include<iomanip>
#include<stdexcept>
#include"package.h"
#include"OvernightPackage.h"
#include"TwoDayPackage.h"

int main(void){
    Package package1{"Grace","NTCU","Taichung","Taiwan",400,"Alice","NYCU","Hsinchu","Taiwan",300,705.5,7.25};
   
    cout<<fixed<<setprecision(2);   //設定小數點後兩位
    cout<<package1.toString();      //把package1的東西輸出
    //下面是測試看看invalid_argument
    try{
        Package package2{"Jasica","NTCU","Taichung","Taiwan",400,"Amber","NYCU","Hsinchu","Taiwan",300,-705.5,0};
    }
    catch(invalid_argument &e){
        cerr<<e.what()<<endl;
    }
    return 0;
}