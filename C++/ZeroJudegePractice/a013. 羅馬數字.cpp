#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int romanToInt(const string&);
string intToRoman(int);
int main(){
    string romanNumber1,romanNumber2;
    while(cin>>romanNumber1>>romanNumber2){
        transform(romanNumber1.begin(), romanNumber1.end(), romanNumber1.begin(), ::toupper);
        transform(romanNumber2.begin(), romanNumber2.end(), romanNumber2.begin(), ::toupper);
        int number1 = romanToInt(romanNumber1);
        int number2 = romanToInt(romanNumber2);
        int diff = abs(number1-number2);
        if(diff==0) {
            cout<<"ZERO"<<endl;
        }
        else{
            cout<<intToRoman(diff)<<endl;
        }
    }
    
    return 0;
}
int romanToInt(const string &s) {
    int value = 0;
    for(int i = 0; i < s.size(); i++){
        int cur = 0;
        switch(s[i]){
            case 'I': cur=1; break;
            case 'V': cur=5; break;
            case 'X': cur=10; break;
            case 'L': cur=50; break;
            case 'C': cur=100; break;
            case 'D': cur=500; break;
            case 'M': cur=1000; break;
        }
        if(i+1 < s.size()){
            int next = 0;
            switch(s[i+1]){
                case 'I': next=1; break;
                case 'V': next=5; break;
                case 'X': next=10; break;
                case 'L': next=50; break;
                case 'C': next=100; break;
                case 'D': next=500; break;
                case 'M': next=1000; break;
            }
            if(cur < next){
                value -= cur; // 減法情況
                continue;
            }
        }
        value += cur;
    }
    return value;
}
string intToRoman(int num) {
    string result;
    pair<int, string> romanNumerals[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
        {1, "I"}
    };
    for(const auto &pair : romanNumerals){
        while(num >= pair.first){
            result += pair.second;
            num -= pair.first;
        }
    }
    return result;
}