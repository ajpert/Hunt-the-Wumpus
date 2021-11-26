CC = g++ -std=c++11 
exe_file = a
$(exe_file): driver.o room.o event.o game.o bat.o wumpus.o gold.o hole.o
	$(CC) driver.o room.o event.o game.o bat.o wumpus.o gold.o hole.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
room.o: room.cpp
	$(CC) -c room.cpp
event.o: event.cpp
	$(CC) -c event.cpp
game.o: game.cpp
	$(CC) -c game.cpp
bat.o: bat.cpp
	$(CC) -c bat.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
hole.o: hole.cpp
	$(CC) -c hole.cpp


clean:
	rm -f *.out *.o $(exe_file)