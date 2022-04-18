#ifndef TICTACTOE_ISFILLED_HPP
#define TICTACTOE_ISFILLED_HPP

string IsFilled(int i) {

	/* Highlights player symbols in different colors to avoid confusion */

	if (Places[i] == 'X')
		return RED;
	else if (Places[i] == 'O')
		return GREEN;
	else
		return RESET;

}

#endif /* TICTACTOE_ISFILLED_HPP */