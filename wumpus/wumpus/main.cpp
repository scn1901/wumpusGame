#include "GameWorld.h"
#include "wumpus.h"

using namespace std;

int main() {
	int cont = 1, score, win = 1;
	char board[5][5], input = '\0';
	GameWorld G1;

	do {
		G1.gameWorld(board);
		do {
			G1.displayVisibleWorld(board);
			printMenu();
			cin >> input;
			switch (input) {
			case 'i':
			case 'I':
				G1.moveUp(board);
				break;
			case 'k':
			case 'K':
				G1.moveDown(board);
				break;
			case 'j':
			case 'J':
				G1.moveLeft(board);
				break;
			case 'l':
			case 'L':
				G1.moveRight(board);
				break;
			case 'v':
			case 'V':
				G1.displayVisibleWorld(board);
				break;
			case 'c':
			case 'C':
				G1.displayEntireWorld(board);
				break;
			case 'r':
			case 'R':
				G1.reset(board);
				break;
			case 'n':
			case 'N':
				win = 2;
				cont = 0;
				break;
			case 'q':
			case 'Q':
				win = 2;
				break;
			default:
				break;
			}
		} while (win == 1);
	} while (cont == 0);

	return 0;
}