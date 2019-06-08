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
	//printSudoku();
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

	return false;
}