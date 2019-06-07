#include "Cell.h"

Cell::Cell()
{
}

Cell::Cell(int num): number(num), possibles()
{
}

int Cell::getNumber()
{
	return number;
}

void Cell::setNumber(int num)
{
	number = num;
}

std::list<int> Cell::getPossiblesList()
{
	return possibles;
}
