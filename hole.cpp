/******************************************************
** Program: hole.cpp
** Author: Andy James
** Date: 5/25/2021
** Description: child of event, overides certain functions
** Input: none
** Output: none
******************************************************/
#include "hole.h"


/****************************************************************************************
** Function: Hole()
** Description: default constructor for the hole class, child of Event
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Hole::Hole() {
    c = "h";
    per = "you feel a breeze";
}


/****************************************************************************************
** Function: action()
** Description: gives the indicator of the hole action
** Parameters: none
** Pre-Condition: none
** Post-Condition: return 4
*****************************************************************************************/
int Hole::action() {
    return 4;
}