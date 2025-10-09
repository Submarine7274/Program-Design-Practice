#include<iostream>
#include<cmath>
using namespace std;
void findroots(int ,int ,int );
int main(){
    int quadraticCoefficient=0, linearCoefficient=0, constantTerm=0;
    cin>>quadraticCoefficient>>linearCoefficient>>constantTerm;
    findroots(quadraticCoefficient,linearCoefficient,constantTerm);
    return 0;
}

void findroots(int quadraticCoefficient,int linearCoefficient,int constantTerm){
    double discriminant = (linearCoefficient*linearCoefficient)-(4.0*quadraticCoefficient*constantTerm);
    if(discriminant>0){
        double root1 = (-linearCoefficient+sqrt(discriminant))/(2.0*quadraticCoefficient);
        double root2 = (-linearCoefficient-sqrt(discriminant))/(2.0*quadraticCoefficient);
        double outputroot1=max(root1,root2);
        double outputroot2=min(root1,root2);
        cout<<"Two different roots x1="<<outputroot1<<" , x2="<<outputroot2<<endl;
    }else if(discriminant==0){
        double root = -linearCoefficient/(2*quadraticCoefficient);
        cout<<"Two same roots x="<<root<<endl;
    }else{
        cout<<"No real root"<<endl;
    }
}