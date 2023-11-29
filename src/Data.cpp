#include "Data.h"


std::map<int, string> Data::dataBase;

void Data::fillDataBase(int categoryChoice) {
	dataBase = {};
	std::string line;
	if (categoryChoice == 1) {
		std::fstream file("flowers.txt");
		
		if (file.is_open()) {
			while (file.eof() == 0) {
				getline(file, line);
				dataBase.insert({int(line[0])-'0',line.substr(2,line.length() - 2)});
			}
			
			file.close();
		}
	}
	else if (categoryChoice == 2) {
		std::fstream file("motorization.txt");

		if (file.is_open()) {
			while (file.eof() == 0) {
				getline(file, line);
				dataBase.insert({ int(line[0]) - '0',line.substr(2,line.length() - 2) });
			}

			file.close();
		}
	}




}