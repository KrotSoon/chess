#include <iostream>
#include <string>
#include "chess.h"

using namespace std;

int main()
{
	chess game;
	string tmp;
	bool isgame = true;

	while(isgame){
		game.setBoard();
		while (game.play());
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> tmp;
		if (tmp != "y")
			isgame = false;
	}

	return 0;
}