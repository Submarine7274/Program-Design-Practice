/* c014. 10035 - Primary Arithmetic
內容
在小學時我們都做過加法的運算，就是把2個整數靠右對齊然後，由右至左一位一位相加。如果相加的結果大於等於10就有進位（carry）的情況出現。你的任務就是要判斷2個整數相加時產生了幾次進位的情況。這將幫助小學老師分析加法題目的難度。

輸入說明
每一列測試資料有2個正整數，長度均小於10位。最後一列有2個0代表輸入結束。

輸出說明
每列測試資料輸出該2數相加時產生多少次進位，請參考Sample Output。注意進位超過1次時operation有加s

範例輸入 #1
123 456
555 555
123 594
0 0
範例輸出 #1
No carry operation.
3 carry operations.
1 carry operation. */
#include<iostream>

int main(){
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long number1=0,number2=0;
    while(cin>>number1>>number2){
        if(number1==0&&number2==0){
            break;
        }
        int carryOperation=0;
        int carry=0;
        while(number1>0||number2>0){
            int digit1= number1%10;
            int digit2= number2%10;
            int sum = digit1 +digit2 +carry;
            if(sum >=10){
                carry = 1;
                carryOperation++;
            }
            else{
                carry = 0;
            }
            number1/=10;
            number2/=10;
        }
        if(carryOperation == 0){
            cout<<"No carry operation."<<endl;
        }
        else if(carryOperation ==1){
            cout<<"1 carry operation."<<endl;
        }
        else{
             cout<<carryOperation<<" carry operations."<<endl;
        }
    }
    return 0; 
}