#include "Hangman.h"
#include <iostream>
#include <string>

using namespace std;

int main () 
{
	HangmanGame game;

	game.setGame();
	game.mainGame();
	game.endGame();

	return 0;
}

