#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include"Event.h"
#include"Time.h"
#include"Date.h"
using namespace std;


Event::Event(string newtitle,Date newdate,Time newtime)
:eventtitle{newtitle},eventDay{newdate},eventTime{newtime}
{

}
Date Event::getEventDate(){
    return eventDay;
}
Time Event::getEventTime(){
    return eventTime;
}
void Event::setEventDate(Date newdate){
    eventDay.setDate(newdate);
}
void Event::setEventTime(Time newtime){
    eventTime.setTime(newtime);
}
void Event::setEventTitle(string newtitle){
    eventtitle = newtitle;
}
string Event::getEventTitle(){
    return eventtitle;
}
string Event::toString(){
    ostringstream output;
    output<<getEventTitle()<<" "<<eventDay.toString()<<" "<<eventTime.toStandardString()<<"\n"
    <<getEventTitle()<<" "<<eventDay.toString()<<" "<<eventTime.toUniversalString()<<endl;
    return output.str();
}