/******************************************************
** Program: hole.h
** Author: Andy James
** Date: 5/25/2021
** Description: header file for hole.cpp, defines functions
** Input: none
** Output: none
******************************************************/
#ifndef HOLE_H
#define HOLE_H

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Hole: public Event{
    public:
        Hole();
        int action();

};
#endif