#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

unsigned int flip();

int main(){
    unsigned int hc{0};
    unsigned int tc{0};
    srand(static_cast<unsigned int>(time(0)));

    for(unsigned int loop{1}; loop <= 100; ++loop){
        if(flip() == 0){
            cout << "Tails ";
            tc++; 
        }
        
        else {
            cout << "Heads ";
            hc++; 
        }
        
        if(loop % 10 == 0){
            cout << endl;
        }
    }
    
    cout << "\n The number of Heads is " << hc 
    << "\n The number of Tails is " << tc
    << endl;
}
unsigned int flip(){
    return rand() % 2;
}