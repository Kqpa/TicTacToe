/*
*
* Header file for Source.cpp
*
*/

#include <iostream>

#include <string>

#include <iomanip>

using std::cin;

using std::cout;

using std::endl;

using std::string;

using std::setw;

#define RESET   "\033[0m"		/* Reset Color */

#define RED     "\033[31m"      /* Red */

#define GREEN   "\033[32m"      /* Green */

char places[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool checkWin();

bool isGameOver();

void resetTable();

