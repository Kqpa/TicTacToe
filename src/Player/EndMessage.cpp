#ifndef TICTACTOE_ENDMESSAGE_HPP
#define TICTACTOE_ENDMESSAGE_HPP

void Player::EndMessage(bool& IsWon, bool& IsOver) {

	/* Prints a win message if the game is won, or if it's a tie */
	
	if (IsWon == true) {

		cout << endl << "> " << this->PlayerColor << this->PlayerName << RESET << " won!" << endl;
		this->PlayerPoint++;

	}
	else if (IsOver == true && IsWon == false)
		cout << endl << "> It's a tie!" << endl;

}

#endif /* TICTACTOE_ENDMESSAGE_HPP */