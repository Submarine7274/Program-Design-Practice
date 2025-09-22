#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int data;
    cin>>data;
    while(data--){
        int r;
        cin>>r;
        vector<int> family(r);
        for(int i =0; i<r;i++){
            cin>>family[i];
        }
        sort(family.begin(), family.end());
        int median = family[r/2];
        int distance = 0;
        for(int i=0; i<r;i++){
            distance += abs(family[i]-median);
        }
        cout<<distance<<endl;
    }
    return 0;
}