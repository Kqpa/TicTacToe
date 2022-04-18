#ifndef TICTACTOE_GETCHART_HPP
#define TICTACTOE_GETCHART_HPP

void Player::GetChart(char Place) {

	/* Prints the current state of the chart & Places player choice */

	if (Place != 'Q') {
		
		for (int i = 0; i < 9; i++) {

			if (Places[i] == (int)Place)
				Places[i] = this->PlayerSymbol;

		}

	}

	PrintTitle();

	cout << "        |     |     " << endl;
	cout << "     " << IsFilled(0) << Places[0] << RESET << "  |" << "  " << IsFilled(1) << Places[1] << RESET << "  |" << "  " << IsFilled(2) << Places[2] << RESET << endl;
	cout << "   _____|_____|_____" << endl;
	cout << "        |     |     " << endl;
	cout << "     " << IsFilled(3) << Places[3] << RESET << "  |" << "  " << IsFilled(4) << Places[4] << RESET << "  |" << "  " << IsFilled(5) << Places[5] << RESET << endl;
	cout << "   _____|_____|_____" << endl;
	cout << "        |     |     " << endl;
	cout << "     " << IsFilled(6) << Places[6] << RESET << "  |" << "  " << IsFilled(7) << Places[7] << RESET << "  |" << "  " << IsFilled(8) << Places[8] << RESET << endl;
	cout << "        |     |     " << endl;

}

#endif /* TICTACTOE_GETCHART_HPP */