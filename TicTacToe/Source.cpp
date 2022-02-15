#include "Core.h"
#include "Func.h"

int main() {

	Player playerOne = Player(0, 'X', RED);
	Player playerTwo = Player(0, 'O', GREEN);
	
	char option = '0', loopCondition, gameMode;
	bool isWon = false, isOver = false;
	int playerChoice;

	printTicTacToe();

	cout << "To play with a " << GREEN << "bot" << RESET << ", type " << GREEN << "1" << RESET << "." << endl;
	cout << "To play with " << RED << "someone else" << RESET << ", type " << RED << "2" << RESET << "." << endl;

	do {

		cout << endl << "> [" << GREEN << "1" << RESET << "/" << RED << "2" << RESET << "]: ";
		cin >> gameMode;
		gameMode = tolower(gameMode);

		if (gameMode != '1' && gameMode != '2') {

			cout << "> Please select a valid option.";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

	} while (gameMode != '1' && gameMode != '2');

	printTicTacToe();

	if (gameMode == '2') {

		do {

			/* Initilize `Player` object data & make sure player names are different */

			cout << "> " << RED << "Player 1" << RESET << ", enter your name: ";
			getline(cin >> std::ws, playerOne.playerName);

			cout << "> " << GREEN << "Player 2" << RESET << ", enter your name: ";
			getline(cin >> std::ws, playerTwo.playerName);

			if (playerOne.playerName == playerTwo.playerName)
				cout << "> Player names have to be different." << endl;

		} while (playerOne.playerName == playerTwo.playerName);

	} else if (gameMode == '1') {

		playerTwo.playerName = "[BOT]";

		do {

			/* Initilize `Player` object data & make sure player names are different */

			cout << "> " << RED << "Player" << RESET << ", enter your name: ";
			getline(cin >> std::ws, playerOne.playerName);

			if (playerOne.playerName == "[BOT]")
				cout << "> Player name cannot be '[BOT]'." << endl;

		} while (playerOne.playerName == "[BOT]");

	}
	
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

		playerChoice = playerOne.selectChoice(playerOne, playerTwo, gameMode);

		playerOne.getChart(playerChoice + '0'); /* The plus '0' casts `int` into `char` by changing the ASCII value */

		isWon = checkWin();

		playerOne.winMessage(isWon);

		/* 2nd Player's Turn */

		isOver = isGameOver();

		loopCondition = checkContinue(isWon, isOver, option, playerOne, playerTwo);

		if (loopCondition == 'b')
			break;
		else if (loopCondition == 'c')
			continue;

		playerChoice = playerTwo.selectChoice(playerOne, playerTwo, gameMode);

		playerTwo.getChart(playerChoice + '0'); /* The plus '0' casts `int` into `char` by changing the ASCII value */

		isWon = checkWin();

		playerTwo.winMessage(isWon);

	}

	cout << endl << "> Press any key to exit. . .";
	cin.ignore();
	cin.get();

	return 0;

}

void Player::getChart(char place) {

	/* Prints the current state of the chart & places player choice */

		for (int i = 0; i < 9; i++) {

			if (places[i] == (int)place)
				places[i] = this->playerSymbol;

		}

		printTicTacToe();

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

int Player::selectChoice(Player &playerOne, Player &playerTwo, char &gameMode) {

	/* Ask user to select the place & ensure it's between 1 and 9 so it can't manupilate the 2nd user's choice & check if slot is already taken */

		int choice;

		if (gameMode == 'h') { /* if game mode human */
	
			do {

				cout << endl << "> " << this->playerColor << this->playerName << RESET << ", pick a slot (1-9): ";
				cin >> choice;

				if ((!(cin)) || (choice < 1) || (choice > 9)) {

					cout << "> Please select a slot between 1-9.";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}

				if ((places[choice - 1]) == ('X'))
					cout << "> Slot " << playerOne.playerColor << choice << RESET << " is already taken by " << playerOne.playerColor << playerOne.playerName << RESET << ".";
				else if ((places[choice - 1]) == ('O'))
					cout << "> Slot " << playerTwo.playerColor << choice << RESET << " is already taken by " << playerTwo.playerColor << playerTwo.playerName << RESET << ".";

			} while ((!(cin)) || (choice < 1) || (choice > 9) || (places[choice - 1]) == ('X') || (places[choice - 1]) == ('O'));

		} else if ((gameMode == '1') && (this->playerName == "[BOT]")) { /* if game mode bot */

			srand (time(NULL));
				
				int randIndex = rand() % 4;
				
				for (int i = 0; i < 9; i++)
				{
					
					int randIndex = rand() % 4;

					if ((places[randIndex] == 'X') || (places[randIndex] == 'O'))
					{
						continue;
					}
					else
					{
						break;
					}
					
				}
		}
		
		return choice;

}


void Player::winMessage(bool& isWon) {

	/* Prints a win message if the game is won */
	
	if (isWon == true) {

		cout << endl << "> " << this->playerColor << this->playerName << RESET << " won!" << endl;
		this->playerPoint++;

	}

}

Player::Player(int point, char symbol, string color) {

	playerPoint = point;
	playerSymbol = symbol;
	playerColor = color;

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

	for (int i = 0; i < 9; i++) {

		places[i] = i + 1 + '0';

	}

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

			cout << endl << "> Game over, play again? (" << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "): ";
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

		cout << endl << "  Player Points:" << endl;
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

void printTicTacToe() {
	
	system("clear"); /* Use system("clear") for g++ */

	cout << endl << endl << "      Tic-Tac-Toe" << endl << endl;

}