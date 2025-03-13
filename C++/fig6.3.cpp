//6.3 找三個數的最大值

#include<iostream>
#include<iomanip>

using namespace std;
int maximum(int x,int y, int z);

int main(void){
    int x, y, z;
    cout<<"Enter three integer";
    cin>>x>>y>>z;
    cout<<"Maximum is :"<<maximum(x,y,z);
    return 0;
}
int maximum(int x, int y, int z){
    int max{x};
    if(y> max){
        max =y;
    }
    if(z> max){
        max =z;
    }
    return max;
}