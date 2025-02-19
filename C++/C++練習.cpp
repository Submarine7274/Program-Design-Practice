#include <iostream>
#include <string> 
using namespace std;

int main() {
    cout << "Hello World!"; // 輸出字串
    cout << 3 * 3;          // 輸出數字不用“”
    cout << "\n";          // 換行
    cout << endl;          // 也是換行 但會將buffer的東西都輸出

    int myNumber = 0;
    myNumber = 7274;
    cout << myNumber;

    int number = 10;
    char character = 'C';
    string text = "this is a string";

    int x=5, y=10, z=15;
    cout << x+y+z;

    const int minutesPerHour = 60;
    cout << minutesPerHour;

    cout <<"Enter a number";
    cin >> number;
    cout << number;

    return 0;
}
