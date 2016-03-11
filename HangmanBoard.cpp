#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Hangman.h"

using namespace std;

HangmanBoard::HangmanBoard()
{
}

HangmanBoard::~HangmanBoard()
{
}

void HangmanBoard::displayHangman(unsigned int wrongGuess)
{
	HangmanGame game;

	cout << "_____________" << endl;
	cout << "|           |" << endl;
	cout << "|";
	if(wrongGuess == 1 || wrongGuess ==2) {
		cout << "           O";
	}
	else if(wrongGuess == 3) {
		cout << "         \\ O";
	}
	else if(wrongGuess >= 4) {
		cout << "         \\ O /";
	}
	cout << endl;
	cout << "|";
	if(wrongGuess >= 2) {
		cout << "           |";
	}
	cout << endl;
	cout << "|";
	if(wrongGuess == 5) {
		cout << "          /";
	}
	else if ( wrongGuess >= 6) {
		cout << "          / \\";
	}
	cout << endl;
	cout << "|" << endl;
	cout << "|_______________" << endl;
}

