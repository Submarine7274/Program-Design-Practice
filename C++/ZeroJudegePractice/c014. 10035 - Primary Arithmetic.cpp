#include<iostream>
using namespace std;
int main(void){
    long long number1, number2;
    while(cin>>number1>>number2){
        if(number1==0 && number2==0){
            break;}
        int carry=0, count=0;
        while(number1>0 || number2>0){
            int digit1=number1%10;
            int digit2=number2%10;
            if(digit1+digit2+carry>=10){
                carry=1;
                count++;
            }
            else{
                carry=0;
            }
            number1/=10;
            number2/=10;
        }
        if(count==0){
            cout<<"No carry operation."<<endl;
        }
        else if(count==1){
            cout<<"1 carry operation."<<endl;
        }
        else{
            cout<<count<<" carry operations."<<endl;
        }
    }
    return 0;
}