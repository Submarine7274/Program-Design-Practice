#include<iostream>
#include"Complex.h"
int main(void){
    Complex number;
    cout<<"Enter a complex number:(EX: 8 + 9i)"<<endl;
    if(cin>>number){
        cout <<"This complex number is:"<<number<<endl;
    }
    else{
        cout<<"Wrong format."<<endl;
    }
    return 0;
}