#include<stdexcept>
#include"Rectangle.h"
using namespace std;

Rectangle::Rectangle(float newlength, float newwidth){
    setLength(newlength);
    setWidth(newwidth);
}

void Rectangle::setLength(float newlength){
    if(newlength >0.0&& newlength < 20.0){
        length =newlength;
    }
    else{
        throw invalid_argument("Length must be between 0.0 and 20.0");
    }
}
void Rectangle::setWidth(float newwidth){
    if(newwidth >0.0&& newwidth < 20.0){
        width =newwidth;
    }
    else{
        throw invalid_argument("Width must be between 0.0 and 20.0");
    }
}
float Rectangle::getLength()const{
    return length;
}
float Rectangle::getWidth()const{
    return width;
}
float Rectangle::perimeter() const{
    return 2*(length+width);
}
float Rectangle::area() const{
    return length*width;
}