#include<iostream>
#include<string>
using namespace std;
int main(void){
    string number;
    while(true){
        cin>>number;
        if(number =="0")
        break;
        int sum_odd=0,sum_even=0;
        for(int i=0;i<number.size();i++){
            if(i%2==0){
                sum_odd+=number[i]-'0';
            }
            else{
                sum_even+=number[i]-'0';
            }
        }
        if((sum_odd-sum_even)%11==0){
            cout<<number<<" is a multiple of 11."<<endl;
        }
        else{
            cout<<number<<" is not a multiple of 11."<<endl;
        }
    }
}