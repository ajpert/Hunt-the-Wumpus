/******************************************************
** Program: room.h
** Author: Andy James
** Date: 5/25/2021
** Description: header file for room.cpp, defines functions
** Input: none
** Output: none
******************************************************/
#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <iostream>
#include <string>

using namespace std;

class Room {
    private:
        bool has_event;
        bool has_player;
        Event* e;
    public:
        Room();
        ~Room();
        Room(Event*);
        void set_has_player(bool);
        void remove_event();
        Event* get_event();
        bool get_has_event();
        bool get_has_player();

        void add_event(Event*);
        void operator=(Room&);


};

#endif