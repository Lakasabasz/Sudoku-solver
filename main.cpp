#include <iostream>
#include "sudoku.h"

using namespace std;

int main()
{
	int problem[9][9] = {
		{0, 1, 0, 9, 5, 0, 0, 0, 2},
		{0, 7, 0, 0, 8, 3, 6, 4, 0},
		{4, 9, 8, 0, 0, 0, 3, 0, 5},
		{5, 0, 1, 0, 0, 0, 9, 3, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 3, 4, 0, 0, 0, 2, 0, 1},
		{7, 0, 9, 0, 0, 0, 4, 2, 6},
		{0, 6, 3, 4, 2, 0, 0, 5, 0},
		{1, 0, 0, 0, 6, 5, 0, 9, 0}
	};

    Sudoku sudoku;
    sudoku.loadFromIntMatrix(problem);
    bool result = sudoku.fullSolve();
    if(!result) {
        cout << "Algorithm couldn't solve this problem\n";
        cout << sudoku.getDisplayString(true);
    }
    else cout << sudoku.getDisplayString();
    return 0;
}
