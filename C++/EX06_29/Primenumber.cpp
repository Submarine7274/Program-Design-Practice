/*測試一個數是不是質數，並印出2~10000間的質數
    質數就是因數只有本身跟1的數
    判斷是否是質數，除了檢查到該數的一半(n/2)的數字以外
    其實檢查到該數的平方根就可以了，即2~√n
*/
#include<iostream>          
#include<cmath>
#include<iomanip>                                                                       //要用setw()函式
using namespace std;

bool isprime(int);                                                                      //函式原型

int main(void){
    int number{2},primeCounts{0};                                                       //變數宣告，從2數到10000的number跟目前有幾個質數的primeCounts
    cout<<"The prime numbers from 1 to 10000 are:"<<endl;
    for(number;number<10000;number++){                                                  //number從2~10000
        if(isprime(number)){                                                            //如果是質數的話
            cout<<setw(5)<<number;                                                      //輸出寬度5的number(因為最多是四位數，五格的話可以省去空格)
            primeCounts++;                                                              //質數的計數+1
            if((primeCounts %10) ==0){                                                  //每10個質數換一行，記得要寫在if裡，不然會在for迴圈裡瘋狂換行
                cout<<endl;
            }
        }
    }
    cout<<endl<<"Total of "<<primeCounts<<" prime numbers between 1 and 10000."<<endl;  //最後輸出質數的數量
    return 0;
}
bool isprime(int n){
    /*假設n不是質數
    代表n = a x b(a 跟b都是自然數，又假設a>=b)
    如果a>√n 則b 必須<√n
    否則 a x b > √n x √n = n
    跟 a x b = n 矛盾
    如果n有因數，至少有一個小於或等於√n的因數
    如果沒有小於√n的因數，一定是質數
*/ 
    for(int i =2; i*i <=n; i++){                                                        //檢查到n的平方根
        if((n % i) ==0){                                                                //如果整除就是因數之一，回傳false              
            return false;
        }
    }
    return true;                                                                        //都沒整除的數，那就是質數
}