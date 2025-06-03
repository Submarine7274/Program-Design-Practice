#include"Complex.h"
#include<string>
#include<sstream>
Complex::Complex():realNumber(0),imaginaryNumber(0){};

istream& operator >>(istream& input, Complex& complexNumber){
    string line;
    if (!getline(input, line)) {
        input.setstate(ios::failbit);
        return input;
    }

    istringstream iss(line);
    int real = 0, imaginary = 0;
    char op = '+', i_char;

    // 嘗試解析格式如：5+3i 或 3i 或 5
    iss >> ws;      //忽略前面空白

    // 嘗試讀取第一個整數（實數或虛數或虛部）
    if (!(iss >> real)) {       //實數沒辦法讀的話 就返回failbit
        input.setstate(ios::failbit);
        return input;
    }

    iss >> ws;      //忽略前面空白

    char next = iss.peek();

    if (next == 'i') {
        // 格式：3i 或 -4i（純虛數）
        iss >> i_char;
        complexNumber.setRealNumber(0);
        complexNumber.setImaginaryNumber(real);
    } else if (next == '+' || next == '-') {
        // 格式：5+3i 或 5-3i
        iss >> op >> ws;
        if (!(iss >> imaginary)) {
            input.setstate(ios::failbit);
            return input;
        }

        if (op == '-') imaginary *= -1;

        iss >> ws;
        if (!(iss >> i_char) || i_char != 'i') {
            input.setstate(ios::failbit);
            return input;
        }

        complexNumber.setRealNumber(real);
        complexNumber.setImaginaryNumber(imaginary);
    } else {
        // 格式：5（純實數）
        iss >> ws;
        if (iss.eof()) {
            complexNumber.setRealNumber(real);
            complexNumber.setImaginaryNumber(0);
        } else {
            input.setstate(ios::failbit);
            return input;
        }
    }

    return input;
}


ostream& operator<<(ostream& output,const Complex&  complexNumber){
    if(complexNumber.getRealNumber()!=0&&complexNumber.getImaginaryNumber()!=0){        //有實數跟虛數
        output<<complexNumber.getRealNumber()<<showpos<<complexNumber.getImaginaryNumber()<<"i"<<noshowpos;
    }else if(complexNumber.getRealNumber()==0 &&complexNumber.getImaginaryNumber()!=0){     //只有虛數
        output<<complexNumber.getImaginaryNumber()<<"i";
    }else if(complexNumber.getRealNumber()!=0 &&complexNumber.getImaginaryNumber()==0){     //只有實數
        output<<complexNumber.getRealNumber();
    }
    else{       //都沒有
        output <<0;
    }
    return output;
}

void Complex::setRealNumber(int number){
    realNumber = number;
}
int Complex::getRealNumber()const{
    return realNumber;
}
void Complex::setImaginaryNumber(int number){
    imaginaryNumber =number;
}
int Complex::getImaginaryNumber()const{
    return imaginaryNumber;
}