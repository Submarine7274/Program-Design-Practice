#include<stdio.h>
int main (void){
    int m, h;
    scanf("%d", &m);
    h = m / 60;
    m %= 60;
    if(h == 24){
        printf("AM:twelve:%d",m);
    }
    else if(h > 12){
        h -= 12;
        switch (h){
        case 1:printf("PM:one:%d",m); break;
        case 2:printf("PM:two:%d",m); break;
        case 3:printf("PM:three:%d",m); break;
        case 4:printf("PM:four:%d",m); break;
        case 5:printf("PM:five:%d",m); break;
        case 6:printf("PM:six:%d",m); break;
        case 7:printf("PM:seven:%d",m); break;
        case 8:printf("PM:eight:%d",m); break;
        case 9:printf("PM:night:%d",m); break;
        case 10:printf("PM:ten:%d",m); break;
        case 11:printf("PM:eleven:%d",m); break;
        case 12:printf("PM:twelve:%d",m); break;}
    }
    else if(h == 12){
        printf("PM:twelve:%02d",m);
    }
    else{
        switch (h){
        case 1:printf("AM:one:%d",m); break;
        case 2:printf("AM:two:%d",m); break;
        case 3:printf("AM:three:%d",m); break;
        case 4:printf("AM:four:%d",m); break;
        case 5:printf("AM:five:%d",m); break;
        case 6:printf("AM:six:%d",m); break;
        case 7:printf("AM:seven:%d",m); break;
        case 8:printf("AM:eight:%d",m); break;
        case 9:printf("AM:night:%d",m); break;
        case 10:printf("AM:ten:%d",m); break;
        case 11:printf("AM:eleven:%d",m); break;
        case 12:printf("AM:twelve:%d",m); break;}
    }
    return 0;
}