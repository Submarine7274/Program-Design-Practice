//6.9

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

unsigned int rollDice();

int main(void){
    enum Status{CONTINUE,WON,LOST};
    int mypoint;
    Status gameStatus;
    srand(static_cast<unsigned int>(time(0)));

    int sumOfDice = rollDice();

    switch (sumOfDice)
    {
    case 7 :
    case 11:
        gameStatus = WON;
    break;
    case 2:
    case 3:
    case 12:
        gameStatus=LOST;
    break;
    default:
        gameStatus =CONTINUE;
        mypoint =sumOfDice;
        cout<<"Point is "<<mypoint<<endl;
        break;
    }
    while(gameStatus ==CONTINUE){
        sumOfDice = rollDice();
        if(sumOfDice ==mypoint){
            gameStatus = WON;
        }
        else{
            if(sumOfDice ==7){
                gameStatus = LOST;
            }
        }
    }
    if(gameStatus == WON){
        cout<<"Player wins"<<endl;
    }
    else{
        cout<<"Player loses"<<endl;
    }
    return 0;
}
unsigned int rollDice(){
    int dice1{1+ rand()%6};                                         //C++11以上
    int dice2{1+ rand()%6};
    int sum = dice1+dice2;
    cout<<"Player rolled"<<dice1<<" + "<<dice2<<" = "<<sum<<endl;
    return sum;
}