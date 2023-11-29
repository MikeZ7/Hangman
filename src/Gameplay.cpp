#include "Gameplay.h"


int Gameplay::seed=0;
int* Gameplay::avaliableAttemptsPtr = &avaliableAttempts;
int Gameplay::avaliableAttempts=7;
std::string Gameplay::correctAnswer="null";
std::string Gameplay::password = "";
std::vector<char> Gameplay::alphabet(27);
std::vector<char> Gameplay::givenLetters{'@'};

void Gameplay::decreseAttempts(void) {
	avaliableAttempts = avaliableAttempts - 1;
}

void Gameplay::setCorrectAnswer(int Seed) {
	correctAnswer = Data{}.dataBase.at(Seed);
	password = "";
	for (int i = 0; i < correctAnswer.length();i++) {
		password += "*";
	}
}

void Gameplay::setSeed(void) {
	seed = 0;
	int wordNumber=0;
	for (auto pair : Data{}.dataBase) {
		wordNumber++;
	}
	srand(time(NULL));
	seed = (rand() % wordNumber) + 1;

}

void Gameplay::fillAplhabet(void) {

	for (int i = 'a';i <= 'z';i++) {
		alphabet[i - 'a'] = char(i);
	}

}

bool Gameplay::wasAlreadyGiven(std::string givenAnswer) {
	bool wasGiven = 0;
	int isInGivenLetters = 0;
	for (int g = 0;g < givenLetters.size();g++) {
		
		if (givenLetters[g] == givenAnswer[0]) {
			wasGiven = 1;

			break;
		}
		else {
			isInGivenLetters++;
		}
		if (isInGivenLetters == givenLetters.size() - 1) {
			wasGiven = 0;
			break;
		}
		
	}
	return wasGiven;
}

void Gameplay::runGame(void) {

	while (true){

		givenLetters = { '@' };
		avaliableAttempts = 7;
		correctAnswer = "null";
		password = "";
		int category = 0;
		Gui{}.menu();
		std::string menuChoice;
		menuChoice = Gui{}.selectMenuOptions();
		system("cls");
		if (menuChoice == "1") {
			category = Gui{}.selectCategory();
			Data{}.fillDataBase(category);
			setSeed();
			setCorrectAnswer(seed);
			fillAplhabet();
			guessLetter();
		}
		else if (menuChoice == "2") {

			Gui{}.howToPlay();
			std::string getKey;
			std::cin >> getKey;
			if (getKey.length() > 0) {
				continue;
			}
			system("cls");
	
		}
		else {
			exit(0);
		}
	}
}

bool Gameplay::isLetter(std::string letter) {
	bool isALetter = 0;
	int errorNumber=0;
	for (int i = 0;i < 27;i++) {
		if (errorNumber == 27) {
			isALetter = 0;
			break;
		}
		if (letter[0] == alphabet[i] || letter[0] == toupper(alphabet[i])) {
			isALetter = 1;
			break;
		}
		else {		
			errorNumber++;			
		}
	}
	return isALetter;

}

void Gameplay::guessLetter(void) {
	int iteratorCount = 0;
	while (true) {

		bool isWin=0;

		system("cls");
		std::cout << "WORD:               " << password << "              remaining attempts: "<<avaliableAttempts << std::endl;
		std::cout << "Already given letters: ";

		for (int f = 0;f < givenLetters.size();f++) {
			
			std::cout << givenLetters[f] << " ";
		}

		if (avaliableAttempts == 0) {
			system("cls");
			std::cout << "You lost! Correct answer was: " <<correctAnswer << " [Press any key]";
			
			std::string getKey;
			std::cin >> getKey;
			if (getKey.length()>0) {
				break;
			}
			
		}
		else {
			std::string givenAnswer;
			bool isALetter = 0;
			int errNumber = 0;
			bool invalidLetter = 0;
			bool wasGiven = 0;
			
			while (true) {
				bool isCorrectLetter = 0;
				
				std::cout << std::endl << "Guess a letter: ";
				std::cin >> givenAnswer;
				if (givenAnswer.length() > 1) {
					std::cout << "You cannot pass two letters at once!"<<std::endl;

				}
				else if (isLetter(givenAnswer) == 0) {
					std::cout << "Type in a letter not a number or symbol!" << std::endl;

				}
				else {
					for (int i = 0;i <= correctAnswer.length()-1;i++) {
						
						if (givenAnswer[0] == correctAnswer[i] || givenAnswer[0] == toupper(correctAnswer[i])) {
		
							for (int j = 0;j <= correctAnswer.length()-1;j++) {
								if (tolower(givenAnswer[0]) == correctAnswer[j]) {
									password[j] = correctAnswer[j];
									isCorrectLetter = 1;
									if (wasAlreadyGiven(givenAnswer) == 1) {
								
									}
									else if (wasAlreadyGiven(givenAnswer) == 0) {
										wasGiven = 0;
										givenLetters.push_back(givenAnswer[0]);
									}

									
								}
								
							}

							break;
						}
						
						else {
							
							errNumber++;
		
						}
						if (errNumber == correctAnswer.length()) {
							
							invalidLetter = 1;
							
							bool wasAlreadyGiven = 0;
							int givenLettersLength = 0;
							for (int v = 0;v < givenLetters.size();v++) {
								if (iteratorCount==0) {
									std::cout << "Invalid letter given try again!" << std::endl;
									*avaliableAttemptsPtr -= 1;
									givenLetters.push_back(givenAnswer[0]);
									break;
								}
								else if (givenLetters[v] == givenAnswer[0]) {
									
										std::cout << "This letter was already given! [Press any key and Enter to continue]" << std::endl;
										std::string getKey;
										std::cin >> getKey;
										if (getKey.length() > 0) {
											break;
										}
				
								}
								
								else {
									givenLettersLength++;
								}
								if (givenLettersLength == givenLetters.size() - 1) {
									std::cout << "Invalid letter given try again!" << std::endl;
									*avaliableAttemptsPtr -= 1;
									givenLetters.push_back(givenAnswer[0]);
									break;
								}

							}
							break;


						}
					}
				}
				if (invalidLetter == 1) {
					break;
				}
				
				if (password == correctAnswer) {

					isWin = 1;
					break;
				}

				if (isCorrectLetter == 1) {
					break;
				}
				if (wasGiven == 1) {
					std::cout << "Letter was already given [Press any key to continue and the press Enter]" << std::endl;
					std::string anyKey;
					std::cin >> anyKey;
					if (anyKey.length() > 0) {
						break;
					}

				}
			

			}
			if (isWin == 1) {
				std::cout << "Congratulations you won! [Press any key and then Enter]" << std::endl;
				std::string getKey;
				std::cin >> getKey;
				if (getKey.length() > 0) {
					break;
				}
				
			
				
			}
		}
		iteratorCount++;
		
	}




}

