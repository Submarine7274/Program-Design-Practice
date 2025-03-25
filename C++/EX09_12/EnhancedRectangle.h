/*做進階版的長方形
能夠輸入第一象限的4個座標軸作為長方形的四個角
每個x或y都在0.0~20.0之間
檢查是不是能構成長方形
長要是兩種邊之間比較長的那個
有一個squre()函式來檢查是否為正方形
*/

#ifndef ENHANCEDRECTANGLE_H
#define ENHANCEDRECTANGLE_H

class EnhancedRectangle{
    public:
    EnhancedRectangle(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4);
    float perimeter();
    float area();
    void setCoordinates(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4);
    bool square();
    float length();
    float width();

    private:
    float x1,y1,x2,y2,x3,y3,x4,y4;
    float distance(float, float, float, float);
};

#endif