/******************************************************
** Program: gold.h
** Author: Andy James
** Date: 5/25/2021
** Description: header file for gold.cpp, defines functions
** Input: none
** Output: none
******************************************************/
#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Gold: public Event{
    public:
        Gold();
        int action();

};
#endif