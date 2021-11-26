/******************************************************
** Program: gold.cpp
** Author: Andy James
** Date: 5/25/2021
** Description: child of event, overides certain functions
** Input: none
** Output: none
******************************************************/
#include "gold.h"

/****************************************************************************************
** Function: gold()
** Description: default constructor for the gold class, child of Event
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Gold::Gold() {
    c = "g";
    per = "you see a glimmer near by";
}


/****************************************************************************************
** Function: action()
** Description: gives the indicator of the gold action
** Parameters: none
** Pre-Condition: none
** Post-Condition: return 3
*****************************************************************************************/
int Gold::action() {
    return 3;
}