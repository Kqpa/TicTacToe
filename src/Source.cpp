#include "../include/std.hpp"
#include "../include/Macros.hpp"
#include "../include/Player.hpp"
#include "./Player/Constructor.cpp"
#include "./Player/EndMessage.cpp"
#include "./Player/GetChart.cpp"
#include "./Player/SelectChoice.cpp"
#include "./CheckContinue.cpp"
#include "./CheckWin.cpp"
#include "./IsFilled.cpp"
#include "./IsGameOver.cpp"
#include "./PrintTitle.cpp"
#include "./ResetTable.cpp"

int main(void) {

	Player PlayerOne = Player(0, 'X', RED);
	Player PlayerTwo = Player(0, 'O', GREEN);
	
	char Option = '0', LoopCondition, GameMode;
	bool IsWon = false, IsOver = false;
	int PlayerChoice;

	PrintTitle();

	cout << "To play with a " << GREEN << "bot" << RESET << ", type " << GREEN << "1" << RESET << "." << endl;
	cout << "To play with " << RED << "someone else" << RESET << ", type " << RED << "2" << RESET << "." << endl;

	do {

		/* Initilize the game mode, ensure that it's either '1' (BOT) or '2' (HUMAN) */

		cout << endl << "> [" << GREEN << "1" << RESET << "/" << RED << "2" << RESET << "]: ";
		cin >> GameMode;
	
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (GameMode != '1' && GameMode != '2') {
			
			cout << "> Please select a valid option.";
			continue;

		} else
			break;

	} while (true);

	PrintTitle();

	if (GameMode == '2') {

		do {

			/* Initilize `Player` object data & make sure player names are different */

			cout << "> " << RED << "Player 1" << RESET << ", enter your name: ";
			getline(cin >> ws, PlayerOne.PlayerName);

			cout << "> " << GREEN << "Player 2" << RESET << ", enter your name: ";
			getline(cin >> ws, PlayerTwo.PlayerName);

			if (PlayerOne.PlayerName == PlayerTwo.PlayerName) {

				cout << "> Player names have to be different." << endl;
				continue;

			} else
				break;

		} while (true);

	} else if (GameMode == '1') {

		PlayerTwo.PlayerName = "[BOT]";

		do {

			/* Initilize the `Player` object and the [BOT] as the 2nd `Player` object & make sure human name is not '[BOT]' */

			cout << "> " << RED << "Player" << RESET << ", enter your name: ";
			getline(cin >> ws, PlayerOne.PlayerName);

			if (PlayerOne.PlayerName == "[BOT]") {

				cout << "> Player name cannot be '[BOT]'." << endl;
				continue;

			} else
				break;

		} while (true);

	}
	
	while (true) {

		if ((Option == '0') || (Option == 'y')) {

			PlayerOne.GetChart('Q'); /* 'Q' is passed as an argument, this skips the placing part & just prints out the table */
			Option = '1'; /* Sets the value of `option` to something other than 'y' and '0' so it doesnt meet the condition again */

		}

		/* 1st Player's Turn */

		LoopCondition = CheckContinue(IsWon, IsOver, Option, PlayerOne, PlayerTwo);

		if (LoopCondition == 'b')
			break;
		else if (LoopCondition == 'c')
			continue;

		PlayerChoice = PlayerOne.SelectChoice(PlayerOne, PlayerTwo, GameMode);

		PlayerOne.GetChart(PlayerChoice + '0');

		IsWon = CheckWin();

		IsOver = IsGameOver();

		PlayerOne.EndMessage(IsWon, IsOver);

		/* 2nd Player's Turn */

		LoopCondition = CheckContinue(IsWon, IsOver, Option, PlayerOne, PlayerTwo);

		if (LoopCondition == 'b')
			break;
		else if (LoopCondition == 'c')
			continue;

		PlayerChoice = PlayerTwo.SelectChoice(PlayerOne, PlayerTwo, GameMode);

		PlayerTwo.GetChart(PlayerChoice + '0');

		IsWon = CheckWin();

		IsOver = IsGameOver();

		PlayerTwo.EndMessage(IsWon, IsOver);

	}

	cout << endl << "> Hit enter to exit. . .";
	cin.get();

	return 0;

}