#include<iostream>
#include<vector>
#ifndef SIZEOFNUMBERS
#define SIZEOFNUMBERS 1000000 //1百萬
#endif
int findNextPrime(int start, const std::vector<bool>& boolVector){
    for(int i=start+1;i<=SIZEOFNUMBERS;i++){
        if(!boolVector[i]){
            return i;
        }
    }
    return -1;
}
void printPrimes(const std::vector<bool>& boolVector){
    using namespace std;
    long long counts = 0;
    for(int i=0;i<boolVector.size();i++){
        if(!boolVector[i]){
            counts++;
            cout<<i<<" ";
            cout<<((i%10)==0 ? "endl" : "");
        }
    }
    cout<<"Total primes: "<<counts<<endl;
}
int main(){
    using namespace std;
    vector<bool> boolVector(SIZEOFNUMBERS+1, false); 
    int k;
    boolVector[0]=true;
    boolVector[1]=true;
    for(k = 2; k*k<=SIZEOFNUMBERS; findNextPrime(k, boolVector)){
        for(int multiple = k*k; multiple <= SIZEOFNUMBERS; multiple += k){
            boolVector[multiple] = true;
        }
    }
    printPrimes(boolVector);
    return 0;
}