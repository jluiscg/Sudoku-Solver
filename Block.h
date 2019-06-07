#pragma once

#include "Cell.h"
#include <list>

class Block
{
public:
	Cell block[3][3];
	std::list<int> missing_numbers;
	Block();
};

