#include "Gui.h"


void Gui::menu(void) {
	system("cls");
	std::fstream file("Logo.txt");
	if (file.is_open()) {
		std::string logo;
		std::cout << std::endl;
		while (file.eof() == 0) {

			
			std::getline(file, logo);
			std::cout <<"                                " << logo << std::endl;
		}
		file.close();
	
	}
	std::cout << std::endl << std::endl;
	std::cout << "                                                  Play [press '1']" << std::endl;
	std::cout << "                                               How to play [press '2']" << std::endl;
	std::cout << "                                                  Exit [press '3']" << std::endl;
	

	

}

std::string Gui::selectMenuOptions(void) {
	
	
	std::string menuChoice = "0";
	
	while (true) {
		std::cout << std::endl << "Select option: ";
		std::cin >> menuChoice;
		if (menuChoice == "1") {
			
			break;
		}
		else if (menuChoice == "2") {
			
			break;
		}
		else if (menuChoice == "3") {
		
			break;
		}
		else if (menuChoice.length() > 1) {
			std::cout << "Type in only one key!" << std::endl;
		}
		else {
			std::cout << "No such option avaliable! Try again!"<<std::endl;
		}
	}


	return menuChoice;

}

void Gui::howToPlay(void) {
	std::cout << "In this game you need to guess a word basing on its length."<<std::endl;
	std::cout << "Every turn you guess a single letter and whether guess is correct or not" << std::endl;
	std::cout << " hidden word would be filled with appropriate letters." << std::endl;
	std::cout << "Game ends when player guess the whole world or if the number of attempts will decrese to 0." << std::endl;
	std::cout << "Good luck!! [Press any key to exit guide]" << std::endl;
}

int Gui::selectCategory(void) {
	std::cout << "Select category of word" << std::endl;
	std::cout << "Flowers [press 1]"<<std::endl;
	std::cout << "Motorization [press 2]" << std::endl;
	std::string categoryChoice;

	while (true) {

		std::cout << "Choose option: " << std::endl;
		std::cin >> categoryChoice;
		if (categoryChoice=="1") {
			categoryChoice = "1";
			break;
		}
		else if (categoryChoice == "2") {
			categoryChoice = "2";
			break;
		}
		else {
			std::cout << "No such option avaliable! Try again!"<<std::endl;
		}
	}
	return stoi(categoryChoice);
}





