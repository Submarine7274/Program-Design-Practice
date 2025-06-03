//題目要求我們要寫出虛數的Class，並要能輸入輸出虛數
#include <iostream>
using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
private:
    int realNumber =0;     //實數部分
    int imaginaryNumber =0;        //虛數部分
public:
    Complex();      //無參數建構子
    friend istream& operator >>(istream& ,Complex&);        //因為要cin虛數，所以要做Operator Overloading
    friend ostream& operator <<(ostream& ,const Complex&);      //因為要cout虛數，同樣要做Operator Overloading
    void setRealNumber(int);
    int getRealNumber()const;
    void setImaginaryNumber(int);
    int getImaginaryNumber()const;
};
#endif