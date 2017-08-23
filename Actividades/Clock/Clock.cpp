/*
Name: Daniela Flores Javier
ID: A01023226
*/

#ifndef CLOCKH_
#define CLOCKH_

#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

class Clock{
    public:
        static Clock* getHour();
        void print_hour();
        
    protected:
        static Clock* hour;

    private:
        Clock(){}
};
#endif

Clock* Clock::hour = 0;

Clock* Clock::getHour(){
    if (!hour){
        hour = new Clock;
    }
    return hour;
}

void Clock::print_hour(){
    char datetime[30];
    
    time_t current_time = time(NULL);
    ctime(&current_time);
    
    strcpy(datetime, ctime(&current_time));
    cout << "Hora actual: " << datetime;
}

int main(int arg, char** argv){
    
    Clock* hour = Clock::getHour();
    hour->print_hour();
    
    return 0;
}