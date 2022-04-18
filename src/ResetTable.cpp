#ifndef TICTACTOE_REESTTABLE_HPP
#define TICTACTOE_REESTTABLE_HPP

void ResetTable() {

	/* Resets table to it's original state if the user wants to play the game again */

	for (int i = 0; i < 9; i++) {

		Places[i] = i + 1 + '0';

	}

}

#endif /* TICTACTOE_REESTTABLE_HPP */