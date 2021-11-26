/******************************************************
** Program: event.h
** Author: Andy James
** Date: 5/25/2021
** Description: header file for event.cpp, defines functions
** Input: none
** Output: none
******************************************************/
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>



using namespace std;

class Event{
    protected:
        string c;
        string per;
    public:
    
        Event();
        void set_name(char);
        void set_percept(string);
        string get_name();
        string get_per();
        virtual int action() = 0;
};
#endif