#ifndef TICTACTOE_PLAYER_HPP
#define TICTACTOE_PLAYER_HPP

class Player {

	public:

		int PlayerPoint;
		
		char PlayerSymbol;
		
		string PlayerName, PlayerColor;
		
		void GetChart(char);

		int SelectChoice(Player&, Player&, char&);

		void EndMessage(bool&, bool&);

		Player(int, char, string);

};

bool CheckWin();

bool IsGameOver();

void ResetTable();

string IsFilled(int);

char CheckContinue(bool&, bool&, char&, Player&, Player&);

void PrintTitle();

#endif /* TICTACTOE_PLAYER_HPP */