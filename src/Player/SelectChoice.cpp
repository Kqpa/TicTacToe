#ifndef TICTACTOE_SELECTCHOICE_HPP
#define TICTACTOE_SELECTCHOICE_HPP

int Player::SelectChoice(Player &PlayerOne, Player &PlayerTwo, char &GameMode) {

	int Choice, RandomIndex;

		if ((GameMode == '2') || (this->PlayerName != "[BOT]")) {
	
			/* Ask user to select the place & ensure it's between 1 and 9 so it can't manupilate the 2nd user's choice & check if slot is already taken */

			do {

				cout << endl << "> " << this->PlayerColor << this->PlayerName << RESET << ", pick a slot (1-9): ";
				cin >> Choice;
				
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');


				if ((!(cin)) || (Choice < 1) || (Choice > 9)) {
					
					cout << "> Please select a slot between 1-9.";
					continue;
				
				}

				if ((Places[Choice - 1]) == ('X')) {
					
					cout << "> Slot " << PlayerOne.PlayerColor << Choice << RESET << " is already taken by " << PlayerOne.PlayerColor << PlayerOne.PlayerName << RESET << ".";
					continue;

				}
				else if ((Places[Choice - 1]) == ('O')) {
				
					cout << "> Slot " << PlayerOne.PlayerColor << Choice << RESET << " is already taken by " << PlayerTwo.PlayerColor << PlayerTwo.PlayerName << RESET << ".";
					continue;

				} else
					break;

			} while (true);

		} else if ((GameMode == '1') && (this->PlayerName == "[BOT]")) {

			/* Find an appropriate place for the bot to make a move which isn't already filled with either 'X' or 'O' */

			srand(time(NULL));
								
				while (true) {

					RandomIndex = rand() % 9;

					if ((Places[RandomIndex] == 'X') || (Places[RandomIndex] == 'O')) {
						
						continue;

					} else {
						
						Choice = RandomIndex + 1;
						break;

					}

				}
		
		}
		
		return Choice;

}

#endif /* TICTACTOE_SELECTCHOICE_HPP */