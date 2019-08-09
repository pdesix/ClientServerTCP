#pragma once
#include <string> 

class Data {
public:
	int getID() const { return ID; }
	std::string getFormattedData() const { return text + ", " + std::to_string(number); }
	Data(int id, int integer, std::string string) : ID{ id }, number{ integer }, text{ string } { }

private:
	int ID, number;
	std::string text;
};