#pragma once
#include <map>
#include <cstdlib>
#include <string>
#include <fstream>
using std::string;

class Data
{
public:

	static std::map <int, string> dataBase;

	static void fillDataBase(int);


};

