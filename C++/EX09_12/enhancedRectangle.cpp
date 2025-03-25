#include<stdexcept>
#include<cmath>
#include"EnhancedRectangle.h"
using namespace std;

EnhancedRectangle::EnhancedRectangle(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){
    setCoordinates(x1,y1,x2,y2,x3,y3,x4,y4);
}
void EnhancedRectangle::setCoordinates(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){
    if( x1 <= 0.0 || x1 >= 20.0 || 
        x2 <= 0.0 || x2 >= 20.0 || 
        x3 <= 0.0 || x3 >= 20.0 || 
        x4 <= 0.0 || x4 >= 20.0 || 
        y1 <= 0.0 || y1 >= 20.0 || 
        y2 <= 0.0 || y2 >= 20.0 || 
        y3 <= 0.0 || y3 >= 20.0 || 
        y4 <= 0.0 || y4 >= 20.0)
        //這邊是判別每個點有沒有符合，有其他方法效率更好，但這樣比較好懂
    {
        throw invalid_argument("Not in first quadrant with value between 0.0 to 20.0");
    }
    float distance1 = distance(x1,y1,x2,y2);
    float distance2 = distance(x1,y1,x3,y3);
    float distance3 = distance(x2,y2,x4,y4);
    float distance4 = distance(x3,y3,x4,y4);
    //這邊看有沒有形成正常的長方形
    if((distance1 != distance4)||(distance2 !=distance3)){
        throw invalid_argument("Cannot form a valid rectangle.");
    }
    else{
        this->x1 = x1; this->y1 = y1;
        this->x2 = x2; this->y2 = y2;
        this->x3 = x3; this->y3 = y3;
        this->x4 = x4; this->y4 = y4;
    }
}
/*pow()語法，pow(值，要幾次方)
sqrt()語法， sqrt(值)
算出兩點距離*/
float EnhancedRectangle::distance(float x1, float y1,float x2,float y2){
    return sqrt(pow((x2-x1),2) +  pow((y2-y1),2));
}
/*長的那邊當長 */
float EnhancedRectangle::length(){
    float distance1 = distance(x1,y1,x2,y2);
    float distance2 = distance(x1,y1,x3,y3);
    return distance1 > distance2? distance1:distance2;
}
/*短的當寬 */
float EnhancedRectangle::width(){
    float distance1 = distance(x1,y1,x2,y2);
    float distance2 = distance(x1,y1,x3,y3);
    return distance1 < distance2? distance1:distance2;
}
//算面積
float EnhancedRectangle::area(){
    return length()*width();
}
//算周長
float EnhancedRectangle::perimeter(){
    return 2*(length()+width());
}
//是不是正方形
bool EnhancedRectangle::square(){
    return length()==width();
}