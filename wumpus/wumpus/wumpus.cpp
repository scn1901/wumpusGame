#include "wumpus.h"

void printMenu() {
	cout << "\tWelcome to Hunt the Wumpus" <<endl;
	cout << "----------------------------------" << endl;
	cout << "\nKey:\n";
	cout << "i or I should move the player up" << endl;
	cout << "k or K should move the player down" << endl;
	cout << "j or J should move the player to the left" << endl;
	cout << "l or L should move the player to the right" << endl;
	cout << "v or V should use the displayVisibleWorld show what is in the caves adjacent to the player" << endl;
	cout << "c or C should cheat and show the entire state of the game using displayEntireWorld function" << endl;
	cout << "r or R should restart the game with the same player" << endl;
	cout << "n or N should restart the game with a new player" << endl;
	cout << "q or Q should end the game" << endl;
}

int playAgain() {
	char again = '\0';

	cout << "Do you want to play again? (y or n) ";
	cin >> again;

	if (again == 'y') {
		return 0;
	}
	else {
		return 1;
	}
}
