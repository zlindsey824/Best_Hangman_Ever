#ifndef CP_H
#define CP_H

#include <iostream>
#include "Hangman.h"
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

CP::CP()
{
	firstFile.assign("lengthWords.txt");
	secondFile.assign("correctLetters1.txt");
	corrLetters1.assign("correctLetters1.txt");
	corrLetters2.assign("correctLetters2.txt");
	char popLetters2[] = {'e','a','o','i','u','y','t','n','s','h','r','d','l','c','m','w','f','g','p','b','v','k','j','x','q','z', '\0'};
	for (unsigned int i = 0; i <= 27; i++)
	{
		popLetters[i] = popLetters2[i];
	}

	numOfGuess = 0;
}


CP::~CP()
{
}

char CP::letterGuess()
{
	char c;

	while (c != popLetters[numOfGuess] && numOfGuess <= 25)
	{
		ifstream rightLength;
		rightLength.open(firstFile.c_str());

		while (rightLength.get(c))
		{
			if (c == popLetters[numOfGuess])
			{
				rightLength.close();
				numOfGuess++;
				return c;
			}
		}
		rightLength.close();
		numOfGuess++;
	}
}

void CP::compareToDictionary(unsigned int length)
{
	ifstream dictionary;
	dictionary.open("words");
	wordLength = length;

	vector<string> possibleWords;
	string possWord;

	while(getline(dictionary, possWord))
	{
		if (possWord.size() == wordLength + 1)
		{
			possibleWords.push_back(possWord);
		}
	}
	ofstream result;
	result.open("lengthWords.txt");
	for (unsigned int i = 0; i < possibleWords.size(); i++)
	{
		result << possibleWords[i] << endl;
	}
	dictionary.close();
	result.close();
}

void CP::wordCompare(string dashedWord)
{
	vector<string> possibleWords;
	bool wrong = false;

	string possWord, temp;

	ifstream rightLength;
	rightLength.open(firstFile.c_str());

	numOfGuess--;

	while (getline(rightLength,possWord))
	{

		for (unsigned int j = 0; j < wordLength; j++)
		{
			if (dashedWord[j] == possWord[j] && possWord[j] == popLetters[numOfGuess])
			{
				for (unsigned int l = 0; l < possWord.size(); l++)
				{
					for (unsigned int k = 0; k < wrongLetters.size(); k++)
					{
						if (possWord[l] == wrongLetters[k])
						{	
							wrong = true;
							break;
						}
					}
					if (wrong)
					{
						break;
					}

					if (dashedWord[l]  == popLetters[numOfGuess] && possWord[l] != popLetters[numOfGuess])
					{
						wrong = true;
						break;
					}
					else if (dashedWord[l]  != popLetters[numOfGuess] && possWord[l] == popLetters[numOfGuess])
					{
						wrong = true;
						break;
					}	
				}
				if (!wrong)
				{
					possibleWords.push_back(possWord);
					break;
				}
				wrong = false;
			}
			else if (dashedWord[j] != possWord[j] && possWord[j] == popLetters[numOfGuess])
			{
				if (possibleWords.size() != 0)
				{
					break;
				}
				break;
			}
		}

	}

	ofstream rightLetters1;
	rightLetters1.open(secondFile.c_str());

	for (unsigned int i = 0; i < possibleWords.size(); i++)
	{
		rightLetters1 << possibleWords[i] << endl;
	}

	rightLength.close();
	rightLetters1.close();

	firstFile.assign(corrLetters1);
	secondFile.assign(corrLetters2);

	temp.assign(corrLetters1);
	corrLetters1.assign(corrLetters2);
	corrLetters2.assign(temp);
	numOfGuess++;
}

void CP::wrongLetter(char c)
{
	wrongLetters.push_back(c);
}

void CP::possWordsByLetter()
{
	vector<string> possibleWords;
	bool wrong = false;

	string possWord, temp;

	ifstream rightLength;
	rightLength.open(firstFile.c_str());

	while (getline(rightLength,possWord))
	{
		for (unsigned int l = 0; l < possWord.size(); l++)
		{
			for (unsigned int k = 0; k < wrongLetters.size(); k++)
			{
				if (possWord[l] == wrongLetters[k])
				{						
					wrong = true;
				}
			}
		}
		if (!wrong)
		{
			possibleWords.push_back(possWord);
		}
		wrong = false;
	}



	ofstream rightLetters1;
	rightLetters1.open(secondFile.c_str());

	for (unsigned int i = 0; i < possibleWords.size(); i++)
	{
		rightLetters1 << possibleWords[i] << endl;
	}

	rightLength.close();
	rightLetters1.close();

	firstFile.assign(corrLetters1);
	secondFile.assign(corrLetters2);

	temp.assign(corrLetters1);
	corrLetters1.assign(corrLetters2);
	corrLetters2.assign(temp);
}


#endif
