/******************************************************
** Program: game.h
** Author: Andy James
** Date: 5/25/2021
** Description: header file for game.cpp, defines functions
** Input: none
** Output: none
******************************************************/
#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "room.h"
#include "event.h"
#include "bat.h"
#include "gold.h"
#include "hole.h"
#include "wumpus.h"
//#include <unistd.h>


using namespace std;

class Game {
    private:
        vector<vector<Room*>> rooms;
        int grid_size;
        int player_row;
        int player_col;
        int initial_row;
        int initial_col;
        int arrows;
        bool game_over;
        bool gold;
        bool debug;
        int gold_row;
        int gold_col;
        bool wump_dead;
        int wump_row;
        int wump_col;
    public:
        ~Game();
        Game(int,bool);
        void same_setup();
        void setup();
        void random_placement(Event*);
        void display_rooms();
        void player_move_or_shoot(string);
        void player_move(string);
        void shoot_arrow(string);
        void shoot_arrow_helper(int, int, int);
        void shot_arrow();
        void remove_wumpus();
        void near_event();
        void on_event();
        bool gold_win();
        bool is_game_over();
};

#endif