/******************************************************
** Program: driver.cpp
** Author: Andy James
** Date: 5/25/2021
** Description:  Driver for running the wumpus game
** Input: int argc, char *argv[]
** Output: none
******************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "room.h"
#include "game.h"
#include "ctime"
//#include <windows.h>

using namespace std;



bool check_input(int argc, char* argv[], bool& debug, int& size);
void run_game(Game&);
void options(int,bool);


/****************************************************************************************
** Function: int main(int argc, char *argv[])
** Description: checks command line and passes it into the game runner
** Parameters: int argc, char *argv[]
** Pre-Condition: pass in a int and a char array, should be the size and true or false
** Post-Condition: none
*****************************************************************************************/
int main(int argc, char *argv[]) {
    srand(time(NULL));
    bool debug;
    int size;
    if(!check_input(argc, argv, debug,size)) { //checks command line and sets values
        cout << "bad command line" << endl;
        return 0;
    }
    cout << "\033[2J\033[1;1H"; //clear screen
    options(size,debug);
}

/****************************************************************************************
** Function: check_input(int argc, char* argv[], bool& debug, int& size)
** Description: checks the command line for size of board (>=4) and true or false
** Parameters: int argc, char* argv[], bool& debug, int& size
** Pre-Condition: pass in the command line arguments, and a bool and int address
** Post-Condition: return true if command line fits requirements, false if else
*****************************************************************************************/
bool check_input(int argc, char* argv[], bool& debug, int& size) {
    if(argc != 3) { //if there are not 3 arguments
        return false;
    }
    for(int i = 0; i < strlen(argv[1]); i++) { //if the 2nd argument is not an int
        if(!isdigit(argv[1][i])) {
            return false;
        }
    }
    if((string)argv[2] == "true") { //if 3rd argument is true, sets to true
        debug = true;
    }
    else if((string)argv[2] == "false") { //if 3rd argument is false, sets to false
        debug = false;
    }
    else {//if 3rd argument is not a bool
        return false;
    }
    size = stoi(argv[1]);
    if(size < 4) { //if the int is 4 or smaller
        cout << "size must be 4 or bigger" << endl;
        return false;
    }
    
    return true;
    
}

/****************************************************************************************
** Function: options(int size, bool debug)
** Description: lets user run game then restart setup, make a new game, or quit
** Parameters: int size, bool debug
** Pre-Condition: pass in an int for size, and bool for showing board
** Post-Condition: none
*****************************************************************************************/
void options(int size, bool debug) {
    Game* game = new Game(size,debug);
    run_game(*game);
    string choice;
    while(true) {
        cout << "would you like to go again?, 1 for same setup, 2 for new game, 3 for quit: ";
        getline(cin,choice);
        cout << "\033[2J\033[1;1H";
        if(choice == "1") { //runs with the same setup
            game->same_setup();
            run_game(*game);
        }
        else if(choice == "2") { //runs with new setup
            delete game;
            game = new Game(size,debug);
            run_game(*game);
        }
        else if(choice == "3") { //quits
            cout << "thank you for playing" << endl;
            break;
        }
        else {
            cout << "that was not an option" << endl;
        }

    }
    delete game;
}

/****************************************************************************************
** Function: run_game(Game& game)
** Description: runs the game with the game class functions
** Parameters: Game& game
** Pre-Condition: pass in a Game object address
** Post-Condition: none
*****************************************************************************************/
void run_game(Game& game) {
    string move_shoot;
    game.display_rooms();
    game.near_event();
    while (true) {
        getline(cin,move_shoot);
        cout << "\033[2J\033[1;1H";
        game.player_move_or_shoot(move_shoot);
        if(game.gold_win() || game.is_game_over()) { //checks game over
            break;
        }
        //game.display_rooms();
        game.near_event();
        game.on_event();
        if(game.is_game_over()) {
            break;
        }
    }
}
