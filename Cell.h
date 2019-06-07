#pragma once

#include <list>

class Cell
{
private:
	int number;
	std::list<int> possibles;
public:
	Cell();
	Cell(int);
	int getNumber();
	void setNumber(int);
	std::list<int> getPossiblesList();
};

