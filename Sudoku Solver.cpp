// Sudoku Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Sudoku.h"

using namespace std;

void readSudokuFromFile(ifstream* file, int m[][9]);
void readSudokuFromConsole(int matrix[][9]);


int main(int argc, char* argv[])
{
	ifstream sudoku_file;
	int sudoku_matrix[9][9];
	char confirmation;
	Sudoku* sudoku = nullptr;
	cout << "SUDOKU SOLVER (unique candidate method)\n";
	if (argc > 1) {
		//try to open specified file
		sudoku_file.open(argv[1],ios_base::in);
		if (sudoku_file.good()) {
			//read from file
			readSudokuFromFile(&sudoku_file, sudoku_matrix);
			sudoku_file.close();
		}
		else {
			//ask for sudoku in console
			cout << "There is  a problem opening the specified file\n";
			readSudokuFromConsole(sudoku_matrix);
		}
	}
	else {
		//ask for sudoku in console
		cout << "No file was specified for sudoku\n";
		readSudokuFromConsole(sudoku_matrix);
	}
	cout << "\nREAD SUDOKU:\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku_matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Is the read sudoku correct?(y/n):";
	cin >> confirmation;
	if (confirmation == 'y') {
		//start solving
		//copy matrix to sudoku object
		sudoku = new Sudoku(sudoku_matrix);
		if (sudoku->solve()) {
			cout << "\nThis is the solved sudoku:\n";
			sudoku->printSudoku();
		}
		else {
			cout << "\nSudoku couldn't be solved, either the sudoku is wrong\nor needs a more complex solution than the unique candidate method\n";
		}
	}
	else {
		//exit program or ask for the position to be corrected
		cout << "Please restart the program and retry entering the sudoku\n";
		cout << "A feature to modify the sudoku is coming later...\n";
	}
	
	//end of program
	if(sudoku != nullptr) delete sudoku;
	cout << "\nPress enter to exit\n";
	cin.ignore();
	cin.ignore();

	return 0;
}

void readSudokuFromFile(ifstream* file, int m[][9])
{
	*file >> m[0][0] >> m[0][1] >> m[0][2] >> m[0][3] >> m[0][4] >> m[0][5] >> m[0][6] >> m[0][7] >> m[0][8];
	*file >> m[1][0] >> m[1][1] >> m[1][2] >> m[1][3] >> m[1][4] >> m[1][5] >> m[1][6] >> m[1][7] >> m[1][8];
	*file >> m[2][0] >> m[2][1] >> m[2][2] >> m[2][3] >> m[2][4] >> m[2][5] >> m[2][6] >> m[2][7] >> m[2][8];
	*file >> m[3][0] >> m[3][1] >> m[3][2] >> m[3][3] >> m[3][4] >> m[3][5] >> m[3][6] >> m[3][7] >> m[3][8];
	*file >> m[4][0] >> m[4][1] >> m[4][2] >> m[4][3] >> m[4][4] >> m[4][5] >> m[4][6] >> m[4][7] >> m[4][8];
	*file >> m[5][0] >> m[5][1] >> m[5][2] >> m[5][3] >> m[5][4] >> m[5][5] >> m[5][6] >> m[5][7] >> m[5][8];
	*file >> m[6][0] >> m[6][1] >> m[6][2] >> m[6][3] >> m[6][4] >> m[6][5] >> m[6][6] >> m[6][7] >> m[6][8];
	*file >> m[7][0] >> m[7][1] >> m[7][2] >> m[7][3] >> m[7][4] >> m[7][5] >> m[7][6] >> m[7][7] >> m[7][8];
	*file >> m[8][0] >> m[8][1] >> m[8][2] >> m[8][3] >> m[8][4] >> m[8][5] >> m[8][6] >> m[8][7] >> m[8][8];
}

void readSudokuFromConsole(int m[][9])
{
	cout << "Please enter the sudoku in the console line by line space separated\nUse 0 (number zero) as missing number\n";
	cin >> m[0][0] >> m[0][1] >> m[0][2] >> m[0][3] >> m[0][4] >> m[0][5] >> m[0][6] >> m[0][7] >> m[0][8];
	cin >> m[1][0] >> m[1][1] >> m[1][2] >> m[1][3] >> m[1][4] >> m[1][5] >> m[1][6] >> m[1][7] >> m[1][8];
	cin >> m[2][0] >> m[2][1] >> m[2][2] >> m[2][3] >> m[2][4] >> m[2][5] >> m[2][6] >> m[2][7] >> m[2][8];
	cin >> m[3][0] >> m[3][1] >> m[3][2] >> m[3][3] >> m[3][4] >> m[3][5] >> m[3][6] >> m[3][7] >> m[3][8];
	cin >> m[4][0] >> m[4][1] >> m[4][2] >> m[4][3] >> m[4][4] >> m[4][5] >> m[4][6] >> m[4][7] >> m[4][8];
	cin >> m[5][0] >> m[5][1] >> m[5][2] >> m[5][3] >> m[5][4] >> m[5][5] >> m[5][6] >> m[5][7] >> m[5][8];
	cin >> m[6][0] >> m[6][1] >> m[6][2] >> m[6][3] >> m[6][4] >> m[6][5] >> m[6][6] >> m[6][7] >> m[6][8];
	cin >> m[7][0] >> m[7][1] >> m[7][2] >> m[7][3] >> m[7][4] >> m[7][5] >> m[7][6] >> m[7][7] >> m[7][8];
	cin >> m[8][0] >> m[8][1] >> m[8][2] >> m[8][3] >> m[8][4] >> m[8][5] >> m[8][6] >> m[8][7] >> m[8][8];
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
