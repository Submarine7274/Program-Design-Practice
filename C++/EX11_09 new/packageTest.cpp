#include<iostream>
#include<iomanip>
#include<stdexcept>
#include"package.h"
#include"OvernightPackage.h"
#include"TwoDayPackage.h"

int main(void){
    Package package1{"Grace","NTCU","Taichung","Taiwan",400,"Alice","NYCU","Hsinchu","Taiwan",300,705.5,7.25};
    TwoDayPackage package2{"Lisa","NTCU","Taichung","Taiwan",400,"Cathy","NTU","Taipei","Taiwan",100,300,7.25,100};
    OvernightPackage package3{"Bianca","NTCU","Taichung","Taiwn",400,"Amily","NCKU","Tainan","Taiwan",700,400,7.25,1.25};
   
    cout<<fixed<<setprecision(2);   //設定小數點後兩位
    cout<<package1.toString()<<endl;      //把package1的東西輸出
    cout<<package2.toString()<<endl;
    cout<<package3.toString()<<endl;
    //下面是測試看看invalid_argument
    try{
        Package package4{"Jasica","NTCU","Taichung","Taiwan",400,"Amber","NYCU","Hsinchu","Taiwan",300,-705.5,0};
    }
    catch(invalid_argument &e){
        cerr<<e.what()<<endl;
    }
    try{
        TwoDayPackage package5{"Jasica","NTCU","Taichung","Taiwan",400,"Amber","NYCU","Hsinchu","Taiwan",300,-705.5,0,-100};
    }
    catch(invalid_argument &e){
        cerr<<e.what()<<endl;
    }
    try{
        OvernightPackage package6{"Jasica","NTCU","Taichung","Taiwan",400,"Amber","NYCU","Hsinchu","Taiwan",300,-705.5,0,-1};
    }
    catch(invalid_argument &e){
        cerr<<e.what()<<endl;
    }
    return 0;
}