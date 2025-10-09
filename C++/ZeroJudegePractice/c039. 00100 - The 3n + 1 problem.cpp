#include<iostream>
using namespace std;
long cycle_length(long n);
long min(long a, long b);
long max(long a, long b);
int main(void){
    long numberi, numberj, count=0;
    while(cin>>numberi>>numberj){
        
        long a=min(numberi, numberj);
        long b=max(numberi, numberj);
        count=0;
        for(long k=a; k<=b; k++){
            long temp=cycle_length(k);
            if(temp>count) count=temp;
        }
        cout<<numberi<<" "<<numberj<<" "<< count <<endl;
    }
    return 0;
}
long cycle_length(long n){
    int count=1;
    while(n!=1){
        if(n%2==1){
            n=3*n+1;
            count++;
        }
        else {
            n=n/2;
            count++;
        }
    }
    return count;
}
long min(long a, long b){
    if(a<b) return a;
    else return b;
}
long max(long a, long b){
    if(a>b) return a;
    else return b;
}