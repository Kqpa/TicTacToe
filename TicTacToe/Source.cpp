#include "Core.hpp"
#include "Func.hpp"

int main(void) {

	Player playerOne = Player(0, 'X', RED);
	Player playerTwo = Player(0, 'O', GREEN);
	
	char option = '0', loopCondition, gameMode;
	bool isWon = false, isOver = false;
	int playerChoice;

	printTitle();

	cout << "To play with a " << GREEN << "bot" << RESET << ", type " << GREEN << "1" << RESET << "." << endl;
	cout << "To play with " << RED << "someone else" << RESET << ", type " << RED << "2" << RESET << "." << endl;

	do {

		/* Initilize the game mode, ensure that it's either '1' (BOT) or '2' (HUMAN) */

		cout << endl << "> [" << GREEN << "1" << RESET << "/" << RED << "2" << RESET << "]: ";
		cin >> gameMode;
	
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (gameMode != '1' && gameMode != '2') {
			
			cout << "> Please select a valid option.";
			continue;

		} else
			break;

	} while (true);

	printTitle();

	if (gameMode == '2') {

		do {

			/* Initilize `Player` object data & make sure player names are different */

			cout << "> " << RED << "Player 1" << RESET << ", enter your name: ";
			getline(cin >> ws, playerOne.playerName);

			cout << "> " << GREEN << "Player 2" << RESET << ", enter your name: ";
			getline(cin >> ws, playerTwo.playerName);

			if (playerOne.playerName == playerTwo.playerName) {

				cout << "> Player names have to be different." << endl;
				continue;

			} else
				break;

		} while (true);

	} else if (gameMode == '1') {

		playerTwo.playerName = "[BOT]";

		do {

			/* Initilize the `Player` object and the [BOT] as the 2nd `Player` object & make sure human name is not '[BOT]' */

			cout << "> " << RED << "Player" << RESET << ", enter your name: ";
			getline(cin >> ws, playerOne.playerName);

			if (playerOne.playerName == "[BOT]") {

				cout << "> Player name cannot be '[BOT]'." << endl;
				continue;

			} else
				break;

		} while (true);

	}
	
	while (true) {

		if ((option == '0') || (option == 'y')) {

			playerOne.getChart('Q'); /* 'Q' is passed as an argument, this skips the placing part & just prints out the table */
			option = '1'; /* Sets the value of `option` to something other than 'y' and '0' so it doesnt meet the condition again */

		}

		/* 1st Player's Turn */

		loopCondition = checkContinue(isWon, isOver, option, playerOne, playerTwo);

		if (loopCondition == 'b')
			break;
		else if (loopCondition == 'c')
			continue;

		playerChoice = playerOne.selectChoice(playerOne, playerTwo, gameMode);

		playerOne.getChart(playerChoice + '0'); /* The plus '0' casts `int` into `char` by changing the ASCII value */

		isWon = checkWin();

		isOver = isGameOver();

		playerOne.endMessage(isWon, isOver);

		/* 2nd Player's Turn */

		loopCondition = checkContinue(isWon, isOver, option, playerOne, playerTwo);

		if (loopCondition == 'b')
			break;
		else if (loopCondition == 'c')
			continue;

		playerChoice = playerTwo.selectChoice(playerOne, playerTwo, gameMode);

		playerTwo.getChart(playerChoice + '0'); /* The plus '0' casts `int` into `char` by changing the ASCII value */

		isWon = checkWin();

		isOver = isGameOver();

		playerTwo.endMessage(isWon, isOver);

	}

	cout << endl << "> Hit enter to exit. . .";
	cin.get();

	return 0;

}

void Player::getChart(char place) {

	/* Prints the current state of the chart & places player choice */

	if (place != 'Q') {		
		
		for (int i = 0; i < 9; i++) {

			if (places[i] == (int)place)
				places[i] = this->playerSymbol;

		}

	}

	printTitle();

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

	int choice, randIndex;

		if ((gameMode == '2') || (this->playerName != "[BOT]")) {
	
			/* Ask user to select the place & ensure it's between 1 and 9 so it can't manupilate the 2nd user's choice & check if slot is already taken */

			do {

				cout << endl << "> " << this->playerColor << this->playerName << RESET << ", pick a slot (1-9): ";
				cin >> choice;
				
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');


				if ((!(cin)) || (choice < 1) || (choice > 9)) {
					
					cout << "> Please select a slot between 1-9.";
					continue;
				
				}

				if ((places[choice - 1]) == ('X')) {
					
					cout << "> Slot " << playerOne.playerColor << choice << RESET << " is already taken by " << playerOne.playerColor << playerOne.playerName << RESET << ".";
					continue;

				}
				else if ((places[choice - 1]) == ('O')) {
				
					cout << "> Slot " << playerTwo.playerColor << choice << RESET << " is already taken by " << playerTwo.playerColor << playerTwo.playerName << RESET << ".";
					continue;

				} else
					break;

			} while (true);

		} else if ((gameMode == '1') && (this->playerName == "[BOT]")) {

			/* Find an appropriate place for the bot to make a move which isn't already filled with either 'X' or 'O' */

			srand(time(NULL));
								
				while (true) {

					randIndex = rand() % 9;

					if ((places[randIndex] == 'X') || (places[randIndex] == 'O')) {
						
						continue;

					} else {
						
						choice = randIndex + 1;
						break;

					}

				}
		
		}
		
		return choice;

}


void Player::endMessage(bool& isWon, bool& isOver) {

	/* Prints a win message if the game is won, or if it's a tie */
	
	if (isWon == true) {

		cout << endl << "> " << this->playerColor << this->playerName << RESET << " won!" << endl;
		this->playerPoint++;

	}
	else if (isOver == true && isWon == false)
		cout << endl << "> It's a tie!" << endl;

}

Player::Player(int point, char symbol, string color) {

	/* Constructor for the `Player` object */

	playerPoint = point;
	playerSymbol = symbol;
	playerColor = color;

}

bool checkWin() {

	/* Checks through every possible combination in order to check if the user won */

	bool isWon = false;

	if (

		((places[0] == places[1]) && (places[1] == places[2])) ||
		((places[3] == places[4]) && (places[4] == places[5])) ||
		((places[6] == places[7]) && (places[7] == places[8])) ||
		((places[0] == places[3]) && (places[3] == places[6])) ||
		((places[1] == places[4]) && (places[4] == places[7])) ||
		((places[2] == places[5]) && (places[5] == places[8])) ||
		((places[0] == places[4]) && (places[4] == places[8])) ||
		((places[2] == places[4]) && (places[4] == places[6]))

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

			cout << endl << "> Game over, play again? [" << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "]: ";
			cin >> option;
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			option = tolower(option);

			if (option != 'y' && option != 'n') {

				cout << "> Please select a valid option.";
				continue;

			} else
				break;


		} while (true);

	}

	if (option == 'n') {

		int diff = 5;

		if (playerOne.playerName.length() > playerTwo.playerName.length())
			diff += playerOne.playerName.length();
		else
			diff += playerTwo.playerName.length();

		cout << endl << "  Player Points:" << endl;
		cout << "> " << playerOne.playerColor << playerOne.playerName << RESET << ": " << right << setw(diff - playerOne.playerName.length()) << playerOne.playerPoint << endl;
		cout << "> " << playerTwo.playerColor << playerTwo.playerName << RESET << ": " << right << setw(diff - playerTwo.playerName.length()) << playerTwo.playerPoint << endl;

		loopCondition = 'b';
		return loopCondition;

	} else if (option == 'y') {

		resetTable();

		loopCondition = 'c';
		return loopCondition;
	
	}

}

void printTitle() {

	/* Prints the title for the game */
	
	#ifdef _WIN32
		system("cls"); /* Windows uses `cls` to clear the console */
	#else
		system("clear"); /* *NIX uses `clear` to clear the console */
	#endif

	cout << endl << endl << "      Tic-Tac-Toe" << endl << endl;

}