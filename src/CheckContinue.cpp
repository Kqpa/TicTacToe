#ifndef TICTACTOE_CHECKCONTINUE_HPP
#define TICTACTOE_CHECKCONTINUE_HPP

char CheckContinue(bool &IsWon, bool &IsOver, char &Option, Player &PlayerOne, Player &PlayerTwo) {

	/* Asks if the user wants to play the game again */

	char LoopCondition;
	
	if (IsOver == true || IsWon == true) {

		IsWon = false;
		IsOver = false;

		do {

			cout << endl << "> Game over, play again? [" << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "]: ";
			cin >> Option;
			
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			Option = tolower(Option);

			if (Option != 'y' && Option != 'n') {

				cout << "> Please select a valid option.";
				continue;

			} else
				break;


		} while (true);

	}

	if (Option == 'n') {

		int Align = 5;

		if (PlayerOne.PlayerName.length() > PlayerTwo.PlayerName.length())
			Align += PlayerOne.PlayerName.length();
		else
			Align += PlayerTwo.PlayerName.length();

		cout << endl << "  Player Points:" << endl;
		cout << "> " << PlayerOne.PlayerColor << PlayerOne.PlayerName << RESET << ": " << right << setw(Align - PlayerOne.PlayerName.length()) << PlayerOne.PlayerPoint << endl;
		cout << "> " << PlayerTwo.PlayerColor << PlayerTwo.PlayerName << RESET << ": " << right << setw(Align - PlayerTwo.PlayerName.length()) << PlayerTwo.PlayerPoint << endl;

		LoopCondition = 'b';
		return LoopCondition;

	} else if (Option == 'y') {

		ResetTable();

		LoopCondition = 'c';
		return LoopCondition;
	
	}

}

#endif /* ICTACTOE_CHECKCONTINUE_HPP */