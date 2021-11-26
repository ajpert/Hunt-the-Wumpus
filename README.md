# Hunt-the-Wumpus
Hunt the Wumpus game made in CS 162(2021) <br />
compile by typing make into the command line and entering <br />
To run, please type ./a (size of board) (bool: true(debug mode), false(regular mode)), ex. ./a 5 true <br />
You can either run in debug mode or regular, with debug showing all the elements. The int determines the size of the board.
The goal of this game is to retrieve the gold and go back to the enterance withount dying <br />
you can move with: a left, s down, w up, and d left. <br />
The elements are as listed, and activate when moved onto: <br />
super bat: moves you to a new location <br />
hole: you die <br />
wumpus: you die <br />
gold: you collect it <br />
<br />
You can attempt to shoot the wumpus by putting a space then a direction (ie " "d) <br />
This travles for 3 blocks, and if it hits the wumpus, it dies. However if it misses, it has a chance to move to a new spot <br />
You will be notified of nearby elements if it is one block away from you in any direction, including diagonals <br />
