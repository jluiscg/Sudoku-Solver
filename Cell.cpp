#include "Cell.h"

Cell::Cell(): number(0)
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
