/******************************************************
** Program: wumpus.h
** Author: Andy James
** Date: 5/25/2021
** Description: header file for wumpus.cpp, defines functions
** Input: none
** Output: none
******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Wumpus: public Event{
    public:
        Wumpus();
        int action();

};
#endif