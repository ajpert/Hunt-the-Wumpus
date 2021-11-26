/******************************************************
** Program: game.cpp
** Author: Andy James
** Date: 5/25/2021
** Description: holds functions for the wumpus game
** Input: int size, bool d
** Output: none
******************************************************/
#include "game.h"

using namespace std;

/****************************************************************************************
** Function: Game(int size,bool d)
** Description: parameterized constructor for the Game class, sets values
** Parameters: int size,bool d
** Pre-Condition: pass in an int for size, and bool for display option
** Post-Condition: none
*****************************************************************************************/
Game::Game(int size,bool d) {
    rooms.resize(size); //allocates memory to rooms vector
    for (int i = 0; i < size; ++i)
        rooms[i].resize(size);
    for(int i = 0; i < size; i++) { //sets each elemnt into a new Room
        for(int j = 0; j < size; j++) {
            rooms[i][j] = new Room;
        }
    }
    player_row = rand()%size;
    player_col = rand()%size;
    initial_row = player_row;
    initial_col= player_col;
    rooms[player_row][player_col]->set_has_player(true); //user starts at random place
    grid_size = size;
    arrows = 3;
    gold = false;
    game_over = false;
    debug = d;
    wump_dead = false;
    setup();
}

/****************************************************************************************
** Function: ~Game()
** Description: Destructor for the Game class
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
Game::~Game() {
    for(int i = 0; i < grid_size; i++) {
        for(auto p : rooms[i]) {
            if(p->get_has_event() == true) {
                delete p->get_event(); //if the room has an event delete it
            }
            delete p;
        }
    }
}

/****************************************************************************************
** Function: display_rooms()
** Description: displays the Room 2d vector with events and player
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::display_rooms()
{
    for (int i = 0; i < grid_size; i++){
        cout << "+---+";
    }
    cout << " Arrows left: " << arrows;
    (gold) ? cout << ", has gold" << endl : cout << ", does not have gold" << endl;
    for (int i = 0; i < grid_size; i++){
        for (int j = 0; j < grid_size; j++){
            cout << "| ";
            if(rooms[i][j]->get_has_player()) { //player output
                cout << "*";
            }
            else if(rooms[i][j]->get_has_event() && debug) { //event output
                cout << rooms[i][j]->get_event()->get_name();
            }
            else if(i == initial_row && j == initial_col && debug) {
                cout << "e";
            }
            else {
                cout << " ";
            }
            cout << " |";
        }
        cout << endl;
        for (int i = 0; i < grid_size; i++){
            cout << "+---+";
        }
        cout << endl;
    }
}

/****************************************************************************************
** Function: setup()
** Description: puts events randomly into the rooms 2d array
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::setup() {
    Event* e;
    
    e = new Gold;
    random_placement(e);
    e = new Wumpus;
    random_placement(e);
    for(int i = 0; i < 2; i++) {
        e = new Bat;
        random_placement(e);
    }
    for(int i = 0; i < 2; i++) {
        e = new Hole;
        random_placement(e);
    }

}

/****************************************************************************************
** Function: same_setup()
** Description: restarts game elements back to original state
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::same_setup() {
    rooms[player_row][player_col]->set_has_player(false);
    player_row = initial_row;
    player_col = initial_col;
    rooms[player_row][player_col]->set_has_player(true);
    gold = false;
    arrows = 3;
    game_over = false;
    wump_dead = false;
    if(!rooms[gold_row][gold_col]->get_has_event()) { //if original gold spot is gone
        rooms[gold_row][gold_col]->add_event(new Gold);
    }
    if(!rooms[wump_row][wump_col]->get_has_event()) { //if wumpus moved
        remove_wumpus();
        rooms[wump_row][wump_col]->add_event(new Wumpus);
    }


}

/****************************************************************************************
** Function: random_placement(Event* e)
** Description: places an Event into a random empty spot in the rooms array
** Parameters: Event* e
** Pre-Condition: pass in an event pointer
** Post-Condition: none
*****************************************************************************************/
void Game::random_placement(Event* e) {
    int rand1;
    int rand2;
    while(true) {
        rand1 = rand()%grid_size;
        rand2 = rand()%grid_size;
        if((rand1 != player_row && rand2 != player_col) && !rooms[rand1][rand2]->get_has_event()) {
            if(e->get_name() == "w") { //if it places a wumpus, save spot
                wump_row = rand1;
                wump_col = rand2;
            }
            if(e->get_name() == "g") { //if it places a gold, save spot
                gold_row = rand1;
                gold_col = rand2;
            }
            rooms[rand1][rand2]->add_event(e);
            break;
        }
    }
}

/****************************************************************************************
** Function: player_move_or_shoot(string s)
** Description: determines if player moves or shoots depending on user input
** Parameters: string s
** Pre-Condition: pass in a string s, user input
** Post-Condition: none
*****************************************************************************************/
void Game::player_move_or_shoot(string s) {
    if(s.size() == 2 && (s).at(0) == ' ') { //if it a shoot like command
        display_rooms();
        if(arrows != 0) { //if they have arrows left
            arrows--;
            shoot_arrow(s);
        }
        else {
            cout << "you are out of arrows" << endl;
        }
    }
    else { //if it is a move command
        player_move(s);
        display_rooms();
    }
}

/****************************************************************************************
** Function: shoot_arrow(string s)
** Description: checks 3 spaces or until wall of direction that user shot for wumpus
** Parameters: string s
** Pre-Condition: pass in a string s, user input
** Post-Condition: none
*****************************************************************************************/
void Game::shoot_arrow(string s) {
    if(s == " w" || s == " s" || s == " a" || s == " d") { //if it is a correct command
        if(s == " w") {
            shoot_arrow_helper(player_row, -1, 0);
        }
        else if(s == " s") {
            shoot_arrow_helper(grid_size - player_row, 1, 0);
        }
        else if(s == " a") {
            shoot_arrow_helper(player_col, 0, -1);
        }
        else if(s == " d") {
            shoot_arrow_helper(grid_size - player_col, 0, 1);
        }
        shot_arrow();
    }
}

/****************************************************************************************
** Function: shoot_arrow_helper(int range, int r_change, int c_change)
** Description: checks in direction based on the change, and the length by range 
** Parameters: int range, int r_change, int c_change
** Pre-Condition: pass in an int for the max range, and -1 to 0 for r_change and c_change for direction
** Post-Condition: none
*****************************************************************************************/
void Game::shoot_arrow_helper(int range, int r_change, int c_change) {
    for(int i = 1; ((i <= 3) && (i < range)); i++) {
        if(rooms[player_row + i*r_change][player_col + i*c_change]->get_has_event())
            if(rooms[player_row + i*r_change][player_col + i*c_change]->get_event()->action() == 2)
                wump_dead = true;
    }
}

/****************************************************************************************
** Function: shot_arrow()
** Description: determines if shot was a miss or a hit, 75% change of moving wumpus if miss
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::shot_arrow() {
    int rand1;
    int rand2;
    if(wump_dead == true) { //if it hit the wumpus
        remove_wumpus();
        cout << "huzza you hit the wumpus" << endl;
    }
    else {
        cout << "you missed" << endl;
        rand1 = rand()%4;
        if(rand1 != 0) {
            remove_wumpus();
            while(true) {
                rand1 = rand()%grid_size;
                rand2 = rand()%grid_size;
                if((rand1 != player_row && rand2 != player_col) && !rooms[rand1][rand2]->get_has_event()) {
                    rooms[rand1][rand2]->add_event(new Wumpus);
                    break;
                }
            }
        }
    }
}

/****************************************************************************************
** Function: remove_wumpus()
** Description: finds the Room with a wumpus in it and removes it
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::remove_wumpus() {
    for(int i = 0; i < grid_size; i++) {
        for(auto p : rooms[i]) {
            if(p->get_has_event() && p->get_event()->action() == 2) {
                p->remove_event();
                break;
            }
        }
    }
}

/****************************************************************************************
** Function: player_move(string s)
** Description: moves player in direction of string s, a left w up etc
** Parameters: string s
** Pre-Condition: pass in a string
** Post-Condition: none
*****************************************************************************************/
void Game::player_move(string s) {
    int old_row = player_row;
    int old_col = player_col;

    if(s == "a") {
        if(player_col != 0) {
            player_col--;
        }
    }
    else if(s == "d") {
        if(player_col != grid_size - 1) {
            player_col++;
        }
    }
    else if(s == "w") {
        if(player_row != 0) {
            player_row--;
        }
    }
    else if(s == "s") {
        if(player_row != grid_size -1) {
            player_row++;
        }
    }
    if(rooms[player_row][player_col]->get_has_event()) {
        rooms[player_row][player_col]->get_event()->action();
    }
    rooms[old_row][old_col]->set_has_player(false);
    rooms[player_row][player_col]->set_has_player(true);
}

/****************************************************************************************
** Function: near_event()
** Description: determines if user is near an event, and gives the percepts if so
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::near_event() {
    for(int i = player_row - 1; i < player_row + 2; i++) {
        for(int j = player_col - 1; j < player_col + 2; j++) {
            if(i >= 0 && j >= 0 && !(i == player_row && j == player_col)) {
                if(i < grid_size && j < grid_size) {
                    if(rooms[i][j]->get_has_event())
                        cout << rooms[i][j]->get_event()->get_per() << endl;
                }
            }
        }
    }

}

/****************************************************************************************
** Function: on_event()
** Description: determines if user is on an event, and does an action based on the event
** Parameters: none
** Pre-Condition: none
** Post-Condition: none
*****************************************************************************************/
void Game::on_event() {
    if(rooms[player_row][player_col]->get_has_event()) {

        if(rooms[player_row][player_col]->get_event()->action() == 1) { //on bat
            rooms[player_row][player_col]->set_has_player(false);
            player_row = rand()%grid_size;
            player_col = rand()%grid_size;
            rooms[player_row][player_col]->set_has_player(true);
            cout << "\033[2J\033[1;1H";
            display_rooms();
            cout << "you ran into some bats and got moved egads" << endl;
            near_event();
            on_event();
            gold_win();
        }
        else if(rooms[player_row][player_col]->get_event()->action() == 2) { //on wumpus
            cout << "you walked into the wumpus and died" << endl;
            game_over = true;
        }
        else if(rooms[player_row][player_col]->get_event()->action() == 3) { //on gold
            cout << "woop de doo you found some gold" << endl;
            rooms[player_row][player_col]->remove_event();
            gold = true;
        }
        else if(rooms[player_row][player_col]->get_event()->action() == 4) { //on hole
            cout << "oh no you fell down a big old hole" << endl;
            game_over = true;
        }
            
        }
}

/****************************************************************************************
** Function: gold_win()
** Description: determines if player won by going back to the start with the gold
** Parameters: none
** Pre-Condition: none
** Post-Condition: return true if they got the gold to the enterance, false if else
*****************************************************************************************/
bool Game::gold_win() {
    if(gold && (player_row == initial_row && player_col == initial_col)) {
        cout << "congrats you made it back with the gold and won" << endl;
        return true;
    }
    return false;

}

/****************************************************************************************
** Function: is_game_over()
** Description: returns the game_over bool
** Parameters: none
** Pre-Condition: none
** Post-Condition: return true if game is over, false if not
*****************************************************************************************/
bool Game::is_game_over() {
    return game_over;
}



