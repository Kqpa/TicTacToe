#include "Source.h"

class ticTacToe {

	public:

		int playerPoint = 0;
		string playerName;
		char playerSymbol;

		void getChart(char place) {

			for (int i = 0; i < 9; i++) {

				if (places[i] == (int)place)
					places[i] = this->playerSymbol;

			}

			system("cls");
		
			cout << "\n\n      Tic-Tac-Toe\n\n";
			cout << "        |     |     " << endl;
			cout << "     " << GREEN << places[0] << RESET << "  |" << "  " << GREEN << places[1] << RESET << "  |" << "  " << GREEN << places[2] << RESET << endl;
			cout << "   _____|_____|_____" << endl;
			cout << "        |     |     " << endl;
			cout << "     " << GREEN << places[3] << RESET << "  |" << "  " << GREEN << places[4] << RESET << "  |" << "  " << GREEN << places[5] << RESET << endl;
			cout << "   _____|_____|_____" << endl;
			cout << "        |     |     " << endl;
			cout << "     " << GREEN << places[6] << RESET << "  |" << "  " << GREEN << places[7] << RESET << "  |" << "  " << GREEN << places[8] << RESET << endl;
			cout << "        |     |     " << endl;

		}

};

int main() {

	char option = '0';
	char playerChoice;
	
	bool isWon = false;
	bool isOver = false;

	ticTacToe playerOne, playerTwo;

	do {

		cout << "\n\n      Tic-Tac-Toe\n\n";

		cout << "> " << GREEN << "Player 1" << RESET << ", enter your name: ";
		cin >> playerOne.playerName;

		playerOne.playerSymbol = 'X';

		cout << "> " << GREEN << "Player 2" << RESET << ", enter your name: ";
		cin >> playerTwo.playerName;

		playerTwo.playerSymbol = 'O';

		if (playerOne.playerName == playerTwo.playerName)
			cout << "> Player names have to be different." << endl;

	} while (playerOne.playerName == playerTwo.playerName);

	while (true) {

		if ((option == '0') || (option == 'y')) {

			playerOne.getChart(NULL);
			option = '-1'; // Sets to random number so doesnt it doesn't meet the condition

		}

		isOver = isGameOver();

		if (isOver == true || isWon == true) {
			
			isWon = false;
			isOver = false;
			
			cout << "\n> Game over, play again? (" << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "): ";
			cin >> option;
			option = tolower(option);

		}

		if (option == 'n') {

			int diff = 5;

			if (playerOne.playerName.length() > playerTwo.playerName.length())
				diff += playerOne.playerName.length();
			else
				diff += playerTwo.playerName.length();
			
			cout << "\n\n  Player Points:\n";
			cout << "> " << GREEN << playerOne.playerName << RESET << ": " << std::right << setw(diff - playerOne.playerName.length()) << playerOne.playerPoint << endl;
			cout << "> " << GREEN << playerTwo.playerName << RESET << ": " << std::right << setw(diff - playerTwo.playerName.length()) << playerTwo.playerPoint << endl;

			break;

		}
		else if (option == 'y') {

			resetTable();
			continue;

		}

		cout << endl << "> " << GREEN << playerOne.playerName << RESET << ", pick a square (1-9): ";
		cin >> playerChoice;

		playerOne.getChart(playerChoice);

		isWon = checkWin();

		if (isWon == true) {
			
			cout << endl << "> " << GREEN << playerOne.playerName << RESET << " won!" << endl;
			playerOne.playerPoint++;
		
		}

		isOver = isGameOver();

		if (isOver == true || isWon == true) {
			
			isWon = false;
			isOver = false;
			
			cout << "\n> Game over, play again? (" << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "): ";
			cin >> option;
			option = tolower(option);

		}

		if (option == 'n') {
			
			int diff = 5;

			if (playerOne.playerName.length() > playerTwo.playerName.length())
				diff += playerOne.playerName.length();
			else
				diff += playerTwo.playerName.length();

			cout << "\n\n  Player Points:\n";
			cout << "> " << GREEN << playerOne.playerName << RESET << ": " << std::right << setw(diff - playerOne.playerName.length()) << playerOne.playerPoint << endl;
			cout << "> " << GREEN << playerTwo.playerName << RESET << ": " << std::right << setw(diff - playerTwo.playerName.length()) << playerTwo.playerPoint << endl;

			break; 

		} else if (option == 'y') {
			
			resetTable();
			continue;
		
		}

		cout << endl << "> " << GREEN << playerTwo.playerName << RESET << ", pick a square (1-9): ";
		cin >> playerChoice;

		playerTwo.getChart(playerChoice);

		isWon = checkWin();

		if (isWon == true) {
			
			cout << endl << "> " << GREEN << playerOne.playerName << RESET << " won!" << endl;
			playerTwo.playerPoint++;

		}

	}

}

bool checkWin() {

	bool isWon = false;
	bool checkOver = false;

	if (

		(places[0] == places[1]) && (places[1] == places[2]) ||
		(places[3] == places[4]) && (places[4] == places[5]) ||
		(places[6] == places[7]) && (places[7] == places[8]) ||
		(places[0] == places[3]) && (places[3] == places[6]) ||
		(places[1] == places[4]) && (places[4] == places[7]) ||
		(places[2] == places[5]) && (places[5] == places[8]) ||
		(places[0] == places[4]) && (places[4] == places[8]) ||
		(places[2] == places[4]) && (places[4] == places[6])

		)
			isWon = true;
			
	return isWon;
}

bool isGameOver() {

	bool isGameOver = false;
	int j = 0;

	for (int i = 0; i < 9; i++) {

		if ((places[i] == 'X') || (places[i] == 'O'))
			j++;

	}

	if (j == 9)
		isGameOver = true;

	return isGameOver;

}

void resetTable() {

	places[0] = '1';
	places[1] = '2';
	places[2] = '3';
	places[3] = '4';
	places[4] = '5';
	places[5] = '6';
	places[6] = '7';
	places[7] = '8';
	places[8] = '9';

}