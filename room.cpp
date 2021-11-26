/******************************************************
** Program: room.cpp
** Author: Andy James
** Date: 5/25/2021
** Description: holds functions for the room class
** Input: none
** Output: none
******************************************************/
#include "room.h" 

using namespace std;

/****************************************************************************************
** Function: Room()
** Description: constructor for the Room class, empty room
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Room::Room() {
    has_event = false;
    has_player = false;
    e = nullptr;
}

/****************************************************************************************
** Function: ~Room()
** Description: destructor for the Room class
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Room::~Room() {
    //delete e;
}

/****************************************************************************************
** Function: get_has_event()
** Description: returns the has_event bool describing if the Room has a event pointer
** Parameters: none
** Pre-Condition: none
** Post-Condition: return has_event
*****************************************************************************************/
bool Room::get_has_event() {
    return has_event;
}

/****************************************************************************************
** Function: get_has_player()
** Description: determines if the Room has a player in it
** Parameters: none
** Pre-Condition: none
** Post-Condition: return the has_player bool
*****************************************************************************************/
bool Room::get_has_player() {
    return has_player;
}

/****************************************************************************************
** Function: set_has_player(bool b)
** Description: sets has_player to bool b
** Parameters: bool b
** Pre-Condition: pass in a bool
** Post-Condition: none
*****************************************************************************************/
void Room::set_has_player(bool b) {
    has_player = b;
}

/****************************************************************************************
** Function: add_event(Event* ptr)
** Description: adds an event pointer to the Event pointer in room
** Parameters: Event* ptr
** Pre-Condition: pass in an Event pointer
** Post-Condition: none
*****************************************************************************************/
void Room::add_event(Event* ptr) {
    e = ptr;
    has_event = true;
}

/****************************************************************************************
** Function: get_event()
** Description: returns the event pointer in a room
** Parameters: none
** Pre-Condition: none
** Post-Condition: return e, event pointer
*****************************************************************************************/
Event* Room::get_event() {
    return e;
}

/****************************************************************************************
** Function: remove_event()
** Description: removes event from the Room object and sets has_event to false
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Room::remove_event() {
    delete e;
    e = nullptr;
    has_event = false;
}

/****************************************************************************************
** Function: operator=(Room&other)
** Description: operator overload for Room
** Parameters: Room address
** Pre-Condition: pass in a room address
** Post-Condition: none
*****************************************************************************************/
void Room::operator=(Room&other) {
    this->has_event = other.has_event;
    this->has_player = other.has_player;
    this->e = other.e;
}