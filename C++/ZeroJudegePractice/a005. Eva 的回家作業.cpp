#include<iostream>
using namespace std;
bool isArithmeticSequence(int a[]);
bool isGeometricSequence(int a[]);
void printSequence(int a[]);
int main(){
    int t_arrays;
    cin>>t_arrays;
    for(int i =0;i<t_arrays;i++){
        int sequence[5];
        for(int j=0;j<4;j++){
            cin>>sequence[j];
        }
        if(isArithmeticSequence(sequence)){
            sequence[4] = sequence[3]+(sequence[1]-sequence[0]);
            printSequence(sequence);
        }else if(isGeometricSequence(sequence)){
            sequence[4] = sequence[3]*(sequence[1]/sequence[0]);
            printSequence(sequence);
        }else{
            cout<<"Arithmetic or Geometric sequence is not found."<<endl;
        }
    }
    return 0;
}
bool isArithmeticSequence(int a[]){
    int d = a[1]-a[0];
    for(int i=1;i<3;i++){
        if(a[i+1]-a[i]!=d){
            return false;
        }
    }
    return true;
}
bool isGeometricSequence(int a[]){
    if(a[0]==0){
        return false;
    }
    if(a[1]%a[0]!=0){
        return false;
    }
    int r = a[1]/a[0];
    for(int i=1;i<3;i++){
        if(a[i]==0||a[i+1]%a[i]!=0||a[i+1]/a[i]!=r){
            return false;
        }
    }
    return true;
}
void printSequence(int a[]){
    for(int i=0;i<5;i++){
        cout<<a[i];
        if(i<4){
            cout<<" ";
        }
    }
    cout<<endl;
}