/******************************************************
** Program: wumpus.cpp
** Author: Andy James
** Date: 5/25/2021
** Description: child of event, overides certain functions
** Input: none
** Output: none
******************************************************/
#include "wumpus.h"

/****************************************************************************************
** Function: Wumpus()
** Description: default constructor for the Wumpus class, child of Event
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Wumpus::Wumpus() {
    c = "w";
    per = "Good lord it smells around here";
}

/****************************************************************************************
** Function: action()
** Description: gives the indicator of the wumpus action
** Parameters: none
** Pre-Condition: none
** Post-Condition: return 2
*****************************************************************************************/
int Wumpus::action() {

    return 2;
}