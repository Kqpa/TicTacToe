/*
*
* @author Kqpa
*
* @date 4/2/2022
*
*/

#include "Core.hpp"

char places[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

class Player {

	public:

		int playerPoint;
		
		char playerSymbol;
		
		string playerName, playerColor;
		
		void getChart(char place);

		int selectChoice(Player&, Player&, char&);

		void endMessage(bool&, bool&);

		Player(int, char, string);

};

bool checkWin();

bool isGameOver();

void resetTable();

string isFilled(int);

char checkContinue(bool&, bool&, char&, Player&, Player&);

void printTitle();