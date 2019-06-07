#pragma once

#include "Block.h"

class Sudoku
{
public:
	Block grid[3][3];
	Sudoku();
	Sudoku(int**);
};

