#include<iostream>
#include<string>
using namespace std;
int main(){
    int shiftAmount=0;
    shiftAmount='*'-'1';
    string inputString,outputString;
    while(getline(cin,inputString)){
        outputString="";
        for(int i=0;i<inputString.length();i++){
            char ch=inputString[i];
            ch+=shiftAmount;
            outputString+=ch;
        }
        cout<<outputString<<endl;
    }
    return 0;
}