/* c024. 10079 - Pizza Cutting
標籤 :
通過比率: 2175人/ 2362人 ( 92%) [非即時]
評分方式： 
最近更新 : 2011-09-21 10:29

內容
Pizza大家都吃過吧！我個人是偏愛達美樂Pizza啦！現在問題來了：給你一塊Pizza，如果切一刀可以切成2塊，切2刀最多可切成4塊，切3刀最多可切成7塊（如下圖），那切N刀最多可以切成幾塊呢？



輸入說明
輸入的每一筆測試資料有1個整數N（0 <= N <= 210000000）代表切幾刀。 如果N為負數，代表輸入結束。
輸出說明
對每一輸入N，輸出切N刀最多可以切成幾塊Pizza。
範例輸入 #1
5
10
-100
範例輸出 #1
16
56 */
#include<iostream>

long long counting_pieces(long long n){
    return ((n*n+n)/2) +1;
}

int main(){
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long cuts=0;
    while(cin>>cuts){
        if(cuts<0){
            break;
        }
        cout<<counting_pieces(cuts)<<endl;
    }
    return 0;
}