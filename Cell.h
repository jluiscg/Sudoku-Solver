#pragma once

#include <list>

class Cell
{
private:
	int number;
public:
	std::list<int> possibles;
	Cell();
	Cell(int);
	int getNumber();
	void setNumber(int);
};

