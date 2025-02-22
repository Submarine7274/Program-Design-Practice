#include<iostream>
#include<cmath>
int main(){
    int len{0}, sac{0}, vc{0}, i{0}; 
    using namespace std;
    cout << "Face lengh\tSurface area\tVolume\nof cube (cm)\tof cube (cm^2)\tof cube (cm^3)\n\n";
    for(i=0; i<=10; i++){
        len = i;
        sac = round(pow(len, 2)*6);
        vc = pow(len, 3);
        cout << len << "\t\t" << sac << "\t\t" << vc << "\n";
    }
    return 0;
}