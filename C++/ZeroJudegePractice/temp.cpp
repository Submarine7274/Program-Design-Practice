#include<iostream>
int main(){
    using namespace std;
    long long number1=0,number2=0;
    while(cin>> number1 >>number2){
        int digit1 =0,digit2 =0;
        int carryOperation=0,carry = 0;
        if(number1 ==0&&number2 ==0){
            break;
        }
        while (number1 >0||number2>0){
            digit1 = number1%10;
            digit2 = number2%10;
            int sum = digit1+digit2+carry;
            if(sum >=10){
                carryOperation++;
                carry = 1;
            }
            else{
                carry = 0;
            }
            number1/=10;
            number2/=10;
        }
        if(carryOperation ==0){
            cout<<"No carry operation.\n";
        }
        else if(carryOperation ==1){
            cout<<"1 carry operation.\n";
        }
        else{
            cout<<carryOperation<<" carry operations.\n";
        }
    }
    return 0;
}