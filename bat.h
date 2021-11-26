/******************************************************
** Program: bat.h
** Author: Andy James
** Date: 5/25/2021
** Description: header file for bat.cpp, defines functions
** Input: none
** Output: none
******************************************************/
#ifndef BAT_H
#define BAT_H

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Bat: public Event{
    public:
        Bat();
        int action();

};
#endif