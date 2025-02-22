//測試C++的輸出功能
#include <iostream>                 //#開頭表示是前置處理，引用標準函式庫用<>包住，用自創header檔用""包住
using namespace std;                //命名空間，等一下解釋
int main(void){                     //int 表示函數回傳值是整數 main()函式整個程式只能有一個 void表示沒傳入參數
    cout<<"This is a C++ program.\n";  //cout是iostream裡面的函式，要使用的話前面都要加std::，如果開頭有宣告using namespace std; 就不用每次用到都要打STD::  \n是換行 \ 是跳脫字元的開頭
    return 0;                       //表示程式正常結束
}                                   //函式要用{}包起來