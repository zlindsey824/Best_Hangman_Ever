#ifndef HANGMAN_H
#define HANGMAN_H
//#include "CP.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class HangmanGame
{
	public:
		HangmanGame(); // default constructor 
		HangmanGame(bool);

		void displayGuesses(); // displays the amount of guesses left
		void setGame(); // sets game (max wrong guesses and number of players)
		void setWordLength(); // sets the word length
		void wordFill();
		void mainGame();
		void endGame();
		~HangmanGame(); // object destructor

		const static unsigned int maxWrong = 6; // maximum number of guesses
		unsigned int wrongGuess; // number of incorrect guesses
		char userGuess; // char guessed by user
		unsigned int wordLength; // length of the word per char
		std::string currentWord;
		std::string dashedWord;
		std::string usedLetters;
		bool gameMode;

		
};


class HangmanBoard : public HangmanGame
{
	public:
		HangmanBoard(); // default constructor

		~HangmanBoard();
		void displayHangman(unsigned int); // displays the fate of pistol pete		
		
};
		
		

		
class CP : public HangmanGame
{
	public:
		CP();
		CP(unsigned int);
		~CP();

		char letterGuess();
		void compareToDictionary(unsigned int);
		void wordCompare(string);
		void wrongLetter(char);
		void possWordsByLetter();

	private:
		unsigned int wordLength;
		string firstFile;
		string secondFile;
		string corrLetters1;
		string corrLetters2;
		char popLetters[27];
		unsigned int numOfGuess;
		vector<char> wrongLetters;

};


#endif				
