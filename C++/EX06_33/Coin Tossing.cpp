/*模擬丟硬幣的程式，每次丟硬幣都要顯示Heads 或Tails 
總共丟一百次硬幣，最後計算正面跟反面有幾次
要有一個function不傳入任何參數，並回傳0代表Tails或1代表Heads，
如果這個程式有遵守亂數，結果應該會接近一半一半
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int flip();

int main (void){
    srand(static_cast<int>(time(0)));                       
    /*為後面的rand()設置隨機的種子值，語法是srand(種子值)
        static_cast<int>是將值轉成整數，語法是static_cast<型別>(要轉換的變數)
        time()函式會回傳1970年1月1日到現在的秒數，回傳的型別是long，因為不符合srand()可以傳入的型別，所以要轉換成int
    */
    unsigned int headsCount{0},tailsCount{0};               //宣告變數headsCount、tailsCount來記錄幾次正面，幾次反面
    for(int loop=1;loop<=100;loop++){                        //投擲一百次硬幣
        if(flip() ==1){                                     //如果正面，就輸出Heads ，並把headsCount+1
            cout<<"Heads ";
            headsCount++;
        }
        else{                                               //如果反面，就輸出Tails ，並把tailsCount+1
            cout<<"Tails ";
            tailsCount++;
        }
        if((loop %10) ==0){
            cout<<endl;
        }
    }
    cout<<endl                                              //輸出最後出現幾次正面跟反面
    <<"The total number of Heads was "<<headsCount<<endl
    <<"The total number of Tails was "<<tailsCount<<endl;
    return 0; 
}
int flip(){                                                 //回傳隨機數除以2的餘數，這樣結果是隨機的0或1
    return rand()%2;
}