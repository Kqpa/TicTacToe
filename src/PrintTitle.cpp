#ifndef TICTACTOE_PRINTTITLE_HPP
#define TICTACTOE_PRINTTITLE_HPP

void PrintTitle() {

	/* Prints the title for the game */
	
	#ifdef _WIN32
		system("cls"); /* Windows uses `cls` to clear the console */
	#else
		system("clear"); /* *NIX uses `clear` to clear the console */
	#endif

	cout << endl << endl << "      Tic-Tac-Toe" << endl << endl;

}

#endif /* TICTACTOE_PRINTTITLE_HPP */