#include <iostream>
#include "Sudoku.h"

Sudoku::Sudoku()
{
}

Sudoku::Sudoku(int m[][9])
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			matrix[i][j] = m[i][j];
		}
	}
}

void Sudoku::printSudoku()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << matrix[i][j].getNumber() << " ";
		}
		std::cout << std::endl;
	}
}

bool Sudoku::solve()
{
	bool changed = false;
	do {
		//clear and update list is a waste of processing time in this version of the algorithm
		clearCandidatesAndMissing();
		updateMissingNumbers();
		updateCellCandidates();
		//findUniqueCandidates() should update these lists when it finds a unique candidate
		changed = findUniqueCandidates();
	} while (changed);
	return checkIfSolved();
}

void Sudoku::clearCandidatesAndMissing()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			matrix[i][j].possibles.clear();
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j].missing_numbers.clear();
		}
	}
}

void Sudoku::updateMissingNumbers()
{
	bool found = false;
	for (int gi = 0; gi < 3; gi++) {
		for (int gj = 0; gj < 3; gj++) {
			//gi gj to through each of the block in the 3x3 grid
			for (int number = 1; number <= 9; number++) {
				found = false;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						//go by the numbers in each block (3x3)
						//multiply the g iterator by the size of each block and add the local iterator to get the 
						//real position in the matrix
						if (matrix[gi * 3 + i][gj * 3 + j].getNumber() == number) {
							found = true;
						}
					}
				}
				if (!found) grid[gi][gj].missing_numbers.push_back(number);
			}
		}
	}
}

void Sudoku::updateCellCandidates()
{
	//check all cells
	for (int gi = 0; gi < 3; gi++) {
		for (int gj = 0; gj < 3; gj++) {
			//gi gj to through each of the block in the 3x3 grid
			//for all the missing numbers in each block
			for (int number : grid[gi][gj].missing_numbers) {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						//only cells that have no number
						if (matrix[gi * 3 + i][gj * 3 + j].getNumber() == 0) {
							//check row and column restriction
							if (checkRowColFor(number, gi * 3 + i, gj * 3 + j)) {
								matrix[gi * 3 + i][gj * 3 + j].possibles.push_back(number);
							}
						}
					}
				}
			}
		}
	}
}

bool Sudoku::checkRowColFor(int num, int row, int col)
{
	bool isCandidate = true;
	//check the row
	for (int i = 0; i < 9; i++) {
		if (matrix[row][i].getNumber() == num) {
			isCandidate = false;
			break;
		}
	}
	//check if the number is still a candidate after checking the row
	if (isCandidate) {
		//check the column
		for (int i = 0; i < 9; i++) {
			if (matrix[i][col].getNumber() == num) {
				isCandidate = false;
				break;
			}
		}
	}
	return isCandidate;
}

bool Sudoku::findUniqueCandidates()
{
	//flag to check if at least 1 unique candidate was found
	//if it's true that means the sudoku changed
	bool found = false;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matrix[i][j].possibles.size() == 1) {
				matrix[i][j].setNumber(matrix[i][j].possibles.front());
				found = true;
				//no need to remove from possibles list in cell or missing list in block in this version of the algorithm 
				//since solve() will call clearCandidatesAndMissing() to clear everything at the end of the pass
				//NOTE that is a waste of processing time to update the lists at every pass
			}
		}
	}
	return found;
}

bool Sudoku::checkIfSolved()
{
	bool solved = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matrix[i][j].getNumber() == 0) {
				solved = false;
				break;
			}
		}
	}
	return solved;
}
