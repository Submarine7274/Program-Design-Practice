/*一個自然數的立方值，其所有的位數相加，等於該自然數，稱為Dudeney Number
例如:
0*0*0=0 0=0
1*1*1=1 1=1
8*8*8=512 5+1+2=8
17*17*17=4913 4+9+1+3=17
18*18*18=5832 5+8+3+2=18
26*26*26=17576 1+7+5+7+6=26
27*27*27=19683 1+9+6+8+3=27
應該只有7個Dudeney Number
寫一個isDudeney 來測試傳入的參數是不是Dudeney Number
<cmath>函式庫裡的cbrt可以得到立方根
*/
#include<iostream>
#include<cmath>
using namespace std;

int sum(int);                                       //這邊放函式原型
bool isDudney(int);


int main (void){
    int dudenneyCount{0},number{0};                 //變數宣告，目前有幾個dudenney number,以及從0開始往上數的自然數;
    cout<<"All 7 Dudeney numbers:"<<endl;           //輸出文字提示
    for(dudenneyCount=0;dudenneyCount<7;number++){  //從0個dudenney number開始算，直到有7個dudenney number，如果不是dudenney number，number會+1往上數
        if(isDudney(number)){                 //如果是dudenney number，就輸出數字並換行
            cout<<number<<endl;
            dudenneyCount++;                        //dudenney number的計數也加1
        }
        else{                                       //不是的dudenney number話就甚麼都不做，並讓for迴圈執行number++
        }
    }
    return 0;
}
int sum(int n){                                     //這個函式是把所有位數相加並傳回去
    int sum{0};
    while(n>0){
        sum += (n%10);
        n/=10;
    }
    return sum;
}
bool isDudney(int n){                         //這個函式判斷是不是dudenney number，把傳進來的數得到他的立方根，如果立方根等於該數所有位數相加，就是dudenney number，回傳true
    double cubeRoot = cbrt(n);
    if(cubeRoot == (sum(n))){
        return true;
    }
    else{
        return false;                               //不是的話就回傳false
    }
}