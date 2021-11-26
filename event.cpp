/******************************************************
** Program: event.cpp
** Author: Andy James
** Date: 5/25/2021
** Description: holds functions for the event class,abstract
** Input: none
** Output: none
******************************************************/
#include "event.h"


using namespace std;

/****************************************************************************************
** Function: Event()
** Description: constructor for the Event class
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Event::Event() {
    c = "n";
    per = "none";
}

/****************************************************************************************
** Function: get_name()
** Description: returns the name of the Event class
** Parameters: none
** Pre-Condition: none
** Post-Condition: return string c
*****************************************************************************************/
string Event::get_name() {
    return c;
}

/****************************************************************************************
** Function: action()
** Description: meant to be overwritten, returns an int based in the Event child
** Parameters: none
** Pre-Condition: none
** Post-Condition: return 0
*****************************************************************************************/
int Event::action() {
    //cout << grid_size << endl;
    return 0;
}

/****************************************************************************************
** Function: get_per()
** Description: gives the percept of the Event class 
** Parameters: none
** Pre-Condition: none
** Post-Condition: return string per
*****************************************************************************************/
string Event::get_per() {
    return per;
}
