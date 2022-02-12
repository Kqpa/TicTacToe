#include "Core.h"
#include "Func.h"

int main() {

	Player playerOne, playerTwo;
	
	char option = '0', loopCondition;
	bool isWon = false, isOver = false;
	int playerChoice;

	system("cls"); /* Use system("clear") for g++ */

	cout << "\n\n      Tic-Tac-Toe\n\n";

	do {

		/* Initilize `Player` object data & make sure player names are different */

		cout << "> " << RED << "Player 1" << RESET << ", enter your name: ";
		getline(cin >> std::ws, playerOne.playerName);

		playerOne.playerSymbol = 'X';
		playerOne.playerPoint = 0;
		playerOne.playerColor = RED;

		cout << "> " << GREEN << "Player 2" << RESET << ", enter your name: ";
		getline(cin >> std::ws, playerTwo.playerName);

		playerTwo.playerSymbol = 'O';
		playerTwo.playerPoint = 0;
		playerTwo.playerColor = GREEN;

		if (playerOne.playerName == playerTwo.playerName)
			cout << "> Player names have to be different." << endl;

	} while (playerOne.playerName == playerTwo.playerName);

	while (true) {

		if ((option == '0') || (option == 'y')) {

			playerOne.getChart(NULL);
			option = '1'; /* Sets the value of `option` to something other than 'y' and '0' so it doesnt meet the condition again */

		}

		/* 1st Player's Turn */

		isOver = isGameOver();

		loopCondition = checkContinue(isWon, isOver, option, playerOne, playerTwo);

		if (loopCondition == 'b')
			break;
		else if (loopCondition == 'c')
			continue;

		playerChoice = playerOne.selectChoice(playerOne, playerTwo);

		playerOne.getChart(playerChoice + '0'); /* The plus '0' casts `int` into `char` by changing the ASCII value */

		isWon = checkWin();

		if (isWon == true) {
			
			cout << endl << "> " << playerOne.playerColor << playerOne.playerName << RESET << " won!" << endl;
			playerOne.playerPoint++;
		
		}

		/* 2nd Player's Turn */

		isOver = isGameOver();

		loopCondition = checkContinue(isWon, isOver, option, playerOne, playerTwo);

		if (loopCondition == 'b')
			break;
		else if (loopCondition == 'c')
			continue;

		playerChoice = playerTwo.selectChoice(playerOne, playerTwo);

		playerTwo.getChart(playerChoice + '0'); /* The plus '0' casts `int` into `char` by changing the ASCII value */

		isWon = checkWin();

		if (isWon == true) {
			
			cout << endl << "> " << playerTwo.playerColor << playerTwo.playerName << RESET << " won!" << endl;
			playerTwo.playerPoint++;

		}

	}

	cout << endl << "> Press any key to exit. . .";
	cin.ignore();
	cin.get();

	return 0;

}

void Player::getChart(char place) {

		for (int i = 0; i < 9; i++) {

			if (places[i] == (int)place)
				places[i] = this->playerSymbol;

		}

		system("cls"); /* Use system("clear") for g++ */

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

int Player::selectChoice(Player &playerOne, Player &playerTwo) {

	/* Ask user to select the place & ensure it's between 1 and 9 so it can't manupilate the 2nd user's choice & check if slot is already taken */

		int choice;

		do {

			cout << endl << "> " << this->playerColor << this->playerName << RESET << ", pick a slot (1-9): ";
			cin >> choice;

			if ( (!(cin)) || (choice < 1) || (choice > 9) ) {

				cout << "> Please select a slot between 1-9.";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}

			if ((places[choice - 1]) == ('X'))
				cout << "Slot " << playerOne.playerColor << choice << RESET << " is already taken by " << playerOne.playerColor << playerOne.playerName << RESET << ".";
			else if ((places[choice - 1]) == ('O'))
				cout << "Slot " << playerTwo.playerColor << choice << RESET << " is already taken by " << playerTwo.playerColor << playerTwo.playerName << RESET << ".";

		} while ((!(cin)) || (choice < 1) || (choice > 9) || (places[choice - 1]) == ('X') || (places[choice - 1]) == ('O'));

		return choice;

}

bool checkWin() {

	/* Checks through every possible combination in order to check if the user won */

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

	/* Checks if the game is over by checking if there isn't anything other than X's & O's */

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

	/* Resets table to it's original state if the user wants to play the game again */

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

string isFilled(int i) {

	/* Highlights player symbols in different colors to avoid confusion */

	if (places[i] == 'X')
		return RED;
	else if (places[i] == 'O')
		return GREEN;
	else
		return RESET;

}

char checkContinue(bool &isWon, bool &isOver, char &option, Player &playerOne, Player &playerTwo) {

	/* Asks if the user wants to play the game again */

	char loopCondition;
	
	if (isOver == true || isWon == true) {

		isWon = false;
		isOver = false;

		do {

			cout << "\n> Game over, play again? (" << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "): ";
			cin >> option;
			option = tolower(option);

			if (option != 'y' && option != 'n') {

				cout << "> Please select a valid option.";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}


		} while (option != 'y' && option != 'n');

	}

	if (option == 'n') {

		int diff = 5;

		if (playerOne.playerName.length() > playerTwo.playerName.length())
			diff += playerOne.playerName.length();
		else
			diff += playerTwo.playerName.length();

		cout << "\n\n  Player Points:\n";
		cout << "> " << playerOne.playerColor << playerOne.playerName << RESET << ": " << std::right << std::setw(diff - playerOne.playerName.length()) << playerOne.playerPoint << endl;
		cout << "> " << playerTwo.playerColor << playerTwo.playerName << RESET << ": " << std::right << std::setw(diff - playerTwo.playerName.length()) << playerTwo.playerPoint << endl;

		loopCondition = 'b';
		return loopCondition;

	}
	else if (option == 'y') {

		resetTable();

		loopCondition = 'c';
		return loopCondition;
	
	}

}