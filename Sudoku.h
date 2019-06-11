#pragma once

#include "Block.h"

class Sudoku
{
public:
	Sudoku();
	Sudoku(int[][9]);
	void printSudoku();
	bool solve();
private:
	Block grid[3][3];
	Cell matrix[9][9];
	void clearCandidatesAndMissing();
	void updateMissingNumbers();
	void updateCellCandidates();
	bool checkRowColFor(int, int, int);
	bool findUniqueCandidates();
	bool checkIfSolved();
};

