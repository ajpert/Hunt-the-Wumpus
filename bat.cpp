/******************************************************
** Program: bat.cpp
** Author: Andy James
** Date: 5/25/2021
** Description: child of event, overides certain functions
** Input: none
** Output: none
******************************************************/
#include "bat.h"

/****************************************************************************************
** Function: bat()
** Description: default constructor for the bat, child of Event
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Bat::Bat() {
    c = "b";
    per = "you hear some annoying flapping sounds";
}

/****************************************************************************************
** Function: action()
** Description: gives the indicator of the bat action
** Parameters: none
** Pre-Condition: none
** Post-Condition: return 1
*****************************************************************************************/
int Bat::action() {
    return 1;
}