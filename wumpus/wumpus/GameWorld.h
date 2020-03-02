#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class GameWorld {
private:
	char board[5][5];
	int pit;
	int pitStart[10][2];
	int playerStart[2];
	int goldStart[2];
	int wumpusStart[2];

public:
	void gameWorld(char[][5]); //constructor
	void displayEntireWorld(char[][5]); 
	void displayVisibleWorld(char[][5]); 
	void moveUp(char[][5]); //setter function
	void moveDown(char[][5]); //setter
	void moveLeft(char[][5]); //setter
	void moveRight(char[][5]); //setter
	bool haveIWon();
	bool amIAlive();
	void reset(char[][5]);
};