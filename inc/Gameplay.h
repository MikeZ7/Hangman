#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include "Data.h"
#include <conio.h>
#include <vector>
#include "Gui.h"
class Gameplay
{
public:
	static std::vector<char> alphabet;
	static std::string correctAnswer;
	static std::string password;
	static int *avaliableAttemptsPtr;
	static int avaliableAttempts;
	static int seed;
	static std::vector<char> givenLetters;
	static void setCorrectAnswer(int);
	static void setSeed(void);
	static void fillAplhabet(void);
	static void runGame(void);
	static void guessLetter(void);
	static bool isLetter(std::string);
	static void decreseAttempts(void);
	static bool wasAlreadyGiven(std::string);


};

