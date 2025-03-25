#include <iostream>
#include "EnhancedRectangle.h"
using namespace std;

int main() {
    try {
        // 設定四個角的座標
        EnhancedRectangle rect1(1.0, 1.0, 1.0, 5.0, 4.0, 5.0, 4.0, 1.0);
        
        // 輸出長度、寬度、周長、面積
        cout << "Length: " << rect1.length() << endl;
        cout << "Width: " << rect1.width() << endl;
        cout << "Perimeter: " << rect1.perimeter() << endl;
        cout << "Area: " << rect1.area() << endl;

        // 檢查是否為正方形
        cout << "Is square: " << (rect1.square() ? "Yes" : "No") << endl;

        // 測試無效的矩形
        EnhancedRectangle rect2(1.0, 1.0, 1.0, 5.0, 6.0, 6.0, 4.0, 1.0); 
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}