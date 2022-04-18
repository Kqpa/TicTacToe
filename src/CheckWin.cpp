#ifndef TICTACTOE_CHECKWIN_HPP	
#define TICTACTOE_CHECKWIN_HPP

bool CheckWin() {

	/* Checks through every possible combination in order to check if the user won */

	bool IsWon = false;

	if (((Places[0] == Places[1]) && (Places[1] == Places[2])) ||
		((Places[3] == Places[4]) && (Places[4] == Places[5])) ||
		((Places[6] == Places[7]) && (Places[7] == Places[8])) ||
		((Places[0] == Places[3]) && (Places[3] == Places[6])) ||
		((Places[1] == Places[4]) && (Places[4] == Places[7])) ||
		((Places[2] == Places[5]) && (Places[5] == Places[8])) ||
		((Places[0] == Places[4]) && (Places[4] == Places[8])) ||
		((Places[2] == Places[4]) && (Places[4] == Places[6]))) {
			IsWon = true;
	}
			
	return IsWon;

}

#endif /* TICTACTOE_CHECKWIN_HPP */