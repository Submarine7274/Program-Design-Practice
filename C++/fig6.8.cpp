//6.8產生1~6的亂數,因為沒有設定srand，所以亂數的順序是一樣的

#include<iostream>
#include<iomanip>                               //用setw()函式，傳入參數是要空幾格的意思
#include<cstdlib>
using namespace std;

int main (void){
    for(int counter =1;counter<=20;counter++){
        cout<<setw(10)<<(1 + rand()%6);         //setw是空10格字元的寬度
        if(counter %5 ==0){
            cout<<endl;
        }
    }
}