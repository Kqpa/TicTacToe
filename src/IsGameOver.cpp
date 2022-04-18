#ifndef TICTACTOE_ISGAMEOVER_HPP
#define TICTACTOE_ISGAMEOVER_HPP

bool IsGameOver() {

	/* Checks if the game is over by checking if there isn't anything other than X's & O's */

	bool IsGameOver = false;
	int j = 0;

	for (int i = 0; i < 9; i++) {

		if ((Places[i] == 'X') || (Places[i] == 'O'))
			j++;

	}

	if (j == 9)
		IsGameOver = true;

	return IsGameOver;

}

#endif /* TICTACTOE_ISGAMEOVER_HPP */