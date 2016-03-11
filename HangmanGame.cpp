#include "Hangman.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

HangmanGame::HangmanGame()
{
}

HangmanGame::HangmanGame(bool player)
{
	gameMode = player;
}

void HangmanGame::displayGuesses()
{
	cout << "Guesses Remaining:" << maxWrong - wrongGuess << endl; 
}

void HangmanGame::setGame() 
{
	unsigned int numOfPlayers;

	cout << "Enter a 1 for 1 player or a 2 for 2 players." << endl;
	cin >> numOfPlayers;

	while (numOfPlayers > 2 || numOfPlayers < 1)
	{
		cout << "Please enter only a 1 or a 2." << endl;
		cin >> numOfPlayers;
	}

	gameMode = numOfPlayers - 1;
}

void HangmanGame::setWordLength()
{
	cout << "enter the word: ";
	cin >> currentWord;
	system("clear");
	wordLength = currentWord.size();
	while(wordLength <=0 || wordLength == 26 || wordLength == 27 || wordLength>29)
	{
		cin.clear();
		cout << "\tincorrect entry for word" << endl;
		cout << "enter the word: ";
		cin >> wordLength;
	}
}

void HangmanGame::wordFill()
{
	for( unsigned int index = 0; index < wordLength; index++ )
	{
		dashedWord = dashedWord + "_"; //fills the string with _ 
	}
}

void HangmanGame::mainGame() 
{
	HangmanBoard board;
	wrongGuess = 0;


	system("clear");
	cout << "\n\n\t" << "          -~==## Welcome to HangmanGame ##==~-	 " << "\n\n\n";
	unsigned int guessNumber = 0;
	CP cpu;
	unsigned int test;

	setWordLength();
	cpu.compareToDictionary(wordLength);
	wordFill();
	
	do{
		bool itFits = false;

		//unsigned int temp = wrongGuess;

		cout << "enter your guess: ";

		if (gameMode == 0)
		{
			userGuess = cpu.letterGuess();

			if (userGuess == NULL)
			{
				cout << "This is not a valid word :/" << endl;
				return;
			}

			cout << userGuess << endl;
		}
		else
		{
			cin >> userGuess;
		}
		cout << endl;
		wrongGuess++;
		for(unsigned int index = 0; index<wordLength; index++) 
		{
			if(userGuess==currentWord[index]) 
			{
				dashedWord[index] = userGuess;
				itFits = true;
			}
		}

		if (gameMode == 0 && itFits)
		{
			wrongGuess--;
			cpu.wordCompare(dashedWord);
		}


		if (gameMode == 0)
		{
			if (!itFits)
			{
				cpu.wrongLetter(userGuess);
				cpu.possWordsByLetter();
			}
		}

//		if(wrongGuess < temp) 
//			wrongGuess = temp;
		if(currentWord == dashedWord) {
			break;
		}



		usedLetters = usedLetters + userGuess + ", "; 


		board.displayHangman(wrongGuess);
		cout << "Word:  "  << dashedWord << endl;
		cout << "Guess: "  << usedLetters << endl;
		displayGuesses();

		guessNumber++;
		if (gameMode == 0)
		{
			cout << "Enter a number to continue" << endl;
			cin >> test;
		}
	}	while( wrongGuess < maxWrong ); 
}

void HangmanGame::endGame()
{
	HangmanBoard board;

	board.displayHangman(wrongGuess);
	if(wrongGuess == maxWrong)	
		cout << "GUESSER LOSES :(" << endl;
	else
		cout << "GUESSER WINS 8-)" << endl;
}	
	
HangmanGame::~HangmanGame()
{
}


