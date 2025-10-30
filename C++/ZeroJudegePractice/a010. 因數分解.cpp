#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector <pair<long long,int>> primeFactorization(long long);
int main(){
    long long n =0;
    cin>>n;
    vector <pair<long long,int>> result = primeFactorization(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i].first;
        if(result[i].second!=1){
            cout<<"^"<<result[i].second;
        }
        if(i!=result.size()-1) cout<<" * ";
    }
    cout<<endl;
    return 0;
}

vector <pair<long long,int>> primeFactorization(long long number){
    long long count =0;
    vector <pair<long long,int>> result;
    while(number%2==0){
        count++;
        number/=2;
    }
    if(count!=0) result.push_back({2,count});
    for(long long i=3;i*i<=number;i+=2){
        count=0;
        while(number%i==0){
            count++;
            number/=i;
        }
        if(count!=0) result.push_back({i,count});
    }
    if(number>2) result.push_back({number,1});
    return result;
}