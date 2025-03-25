/*做一個長方形class 有長寬的屬性 預設是1
要提供能計算周長、面積的member function
還有set 跟get function
長寬的set 要限制0.0~20.0之間*/
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle(float length=1.0, float width=1.0);
    void setLength(float);
    void setWidth(float);

    float getLength() const;
    float getWidth() const;

    float perimeter() const;
    float area() const;

private:
    float length{1};
    float width{1};
};
#endif