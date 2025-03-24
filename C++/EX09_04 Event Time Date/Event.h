#include <string>
#include"Time.h"
#include"Date.h"
#ifndef EVENT_H
#define ENENT_H
using namespace std;


class Event{
    public:
        Event(string,Date,Time);
        void setEventDate(Date);
        Date getEventDate();
        void setEventTime(Time);
        Time getEventTime();
        void setEventTittle(string);
        string getEventTittle();
        string toString();
    private:
        Date eventDay;
        Time eventTime;
        string eventtitle;
};

#endif