/*
*
* @author Kqpa
*
* @date 4/2/2022
*
*/

#include "Core.h"

char places[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool checkWin();

bool isGameOver();

void resetTable();

string isFilled(int);

class Player {

public:

	int playerPoint;
	char playerSymbol;
	string playerName;
	string playerColor;

	void getChart(char place) {

		for (int i = 0; i < 9; i++) {

			if (places[i] == (int)place)
				places[i] = this->playerSymbol;

		}

		system("cls"); /* Clears screen, use system("clear") if you're compiling using g++ */

		cout << "\n\n      Tic-Tac-Toe\n\n";
		cout << "        |     |     " << endl;
		cout << "     " << isFilled(0) << places[0] << RESET << "  |" << "  " << isFilled(1) << places[1] << RESET << "  |" << "  " << isFilled(2) << places[2] << RESET << endl;
		cout << "   _____|_____|_____" << endl;
		cout << "        |     |     " << endl;
		cout << "     " << isFilled(3) << places[3] << RESET << "  |" << "  " << isFilled(4) << places[4] << RESET << "  |" << "  " << isFilled(5) << places[5] << RESET << endl;
		cout << "   _____|_____|_____" << endl;
		cout << "        |     |     " << endl;
		cout << "     " << isFilled(6) << places[6] << RESET << "  |" << "  " << isFilled(7) << places[7] << RESET << "  |" << "  " << isFilled(8) << places[8] << RESET << endl;
		cout << "        |     |     " << endl;

	}

	int selectChoice() {

		int choice;

		do {

			cout << endl << "> " << this->playerColor << this->playerName << RESET << ", pick a square (1-9): ";
			cin >> choice;

			if (choice < 1 || choice > 9) {

				cout << "> Please select an option between 1-9.";

			}

		} while (choice < 1 || choice > 9);

		return choice;

	}

};

char checkContinue(bool&, bool&, char&, Player&, Player&);