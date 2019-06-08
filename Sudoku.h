#pragma once

#include "Block.h"

class Sudoku
{
public:
	Block grid[3][3];
	Cell matrix[9][9];
	Sudoku();
	Sudoku(int[][9]);
	void printSudoku();
	bool solve();
};

