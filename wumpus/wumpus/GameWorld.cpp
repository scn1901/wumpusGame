#include "GameWorld.h"

void GameWorld::gameWorld(char board[][5]) {
	int row = 0, col = 0, i = 0;
	char boardValues[4] = { 'P','U','G','W' };

	pit = rand() % 5 + 6;
	for (i = 0; i < pit; i++) {
		do {
			row = rand() % 5;
			col = rand() % 5;
		} while (board[row][col] != NULL);
		board[row][col] = 'P';
		pitStart[i][0] = row;
		pitStart[i][1] = col;
	}
	for (i = 1; i < 4; i++) {
		do {
			row = rand() % 5;
			col = rand() % 5;
		} while (board[row][col] != NULL);
		board[row][col] = boardValues[i];
		switch (i) {
		case 1:
			playerStart[0] = row;
			playerStart[1] = col;
			break;
		case 2:
			goldStart[0] = row;
			goldStart[1] = col;
			break;
		case 3: 
			wumpusStart[0] = row;
			wumpusStart[1] = col;
		}
	}
	for (row = 0; row < 5; row++) {
		for (col = 0; col < 5; col++) {
			if (board[row][col] == NULL) {
				board[row][col] = ' ';
			}
		}
	}
}

void GameWorld::displayEntireWorld(char board[][5]) {
	int row = 0, col = 0;
	
	for (row = 0; row < 5; row++) {
		for (row = 0; row < 15; row++) {
			cout << "-" << endl;
		}
		for (col = 0; col < 5; col++) {
			cout << "|" << board[row][col] << "|";
		}
		cout << endl;
	}
	for (row = 0; row < 15; row++) {
		cout << "-" << endl;
	}
}

void GameWorld::displayVisibleWorld(char board[][5]) {
	int row = 0, col = 0, i = 0;

	for (row = 0; row < 5; row++) {
		for (i = 0; i < 15; i++) {
			cout << "-" << endl;
		}
		for (col = 0; col < 5; col++) {
			cout << "|";
			if (board[row][col] == 'U') {
				cout << board[row][col];
			}
			else {
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
	}
	for (i = 0; i < 15; i++) {
		cout << "-" << endl;
	}
}

void GameWorld::moveUp(char board[][5]) {
	int found = 1, row = 0, col = 0;
	while (row < 5 && found == 1) {
		col = 0;
		while (col < 5 && found == 1) {
			if (board[row][col] == 'U') {
				found = 0;
			}
			else {
				col++;
			}
		}
		if (found != 0) {
			row++;
		}
	}
	if (row == 0) {
		cout << "You can't move any further." << endl;
	}
	else {
		board[row][col] = ' ';
		board[row - 1][col] = 'U';
	}
}

void GameWorld::moveDown(char board[][5]) {
	int found = 1, row = 0, col = 0;
	while (row < 5 && found == 1) {
		col = 0;
		while (col < 5 && found == 1) {
			if (board[row][col] == 'U') {
				found = 0;
			}
			else {
				col++;
			}
		}
		if (found != 0) {
			row++;
		}
	}
	if (row == 4) {
		cout << "You can't move any further." << endl;
	}
	else {
		board[row][col] = ' ';
		board[row + 1][col] = 'U';
	}
}

void GameWorld::moveLeft(char board[][5]) {
	int found = 1, row = 0, col = 0;
	while (row < 5 && found == 1) {
		col = 0;
		while (col < 5 && found == 1) {
			if (board[row][col] == 'U') {
				found = 0;
			}
			else {
				col++;
			}
		}
		if (found != 0) {
			row++;
		}
	}
	if (col == 0) {
		cout << "You can't move any further." << endl;
	}
	else {
		board[row][col] = ' ';
		board[row][col - 1] = 'U';
	}
}

void GameWorld::moveRight(char board[][5]) {
	int found = 1, row = 0, col = 0;
	while (row < 5 && found == 1) {
		col = 0;
		while (col < 5 && found == 1) {
			if (board[row][col] == 'U') {
				found = 0;
			}
			else {
				col++;
			}
		}
		if (found != 0) {
			row++;
		}
	}
	if (col == 4) {
		cout << "You can't move any further." << endl;
	}
	else {
		board[row][col] = ' ';
		board[row][col + 1] = 'U';
	}
}

bool GameWorld::haveIWon() {
	bool status = true;

	if (board[goldStart[0]][goldStart[1]] == 'U') {
		status = true;
	}
	else {
		status = false;
	}

	return status;
}

bool GameWorld::amIAlive() {
	int i = 0;

	for (i = 0; i < pit; i++) {
		if (board[pitStart[i][0]][pitStart[i][1]] == 'U') {
			return false;
		}
	}
	if (board[wumpusStart[0]][wumpusStart[1]] == 'U') {
		return false;
	}
	else {
		return true;
	}
}

void GameWorld::reset(char board[][5]) {
	int row = 0, col = 0, i = 0;
	bool status = false;

	while (row < 5 && status == false) {
		col = 0;
		while (col < 5 && status == false) {
			if (board[row][col] == 'U') {
				status = true;
			}
			else {
				col++;
			}
		}
		if (status != true) {
			row++;
		}
	}
	board[row][col] = ' ';
	board[playerStart[0]][playerStart[1]] = 'U';
	for (i = 0; i < pit; i++) {
		board[pitStart[i][0]][pitStart[i][1]] = 'P';
	}
	board[wumpusStart[0]][wumpusStart[1]] = 'W';
	board[goldStart[0]][goldStart[1]] = 'G';

}