#include <iostream>
#include "sudoku.h"

using namespace std;

int main()
{
    int** problem = new int*[9];
    for(int i = 0; i<9; i++) problem[i] = new int[9];

    string s[9]{
        "010950002",
        "070083640",
        "498000305",
        "501000930",
        "000010000",
        "034000201",
        "709000426",
        "063420050",
        "100065090"
    };
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            problem[i][j] = s[i][j] - '0';
        }
    }

    Sudoku sudoku;
    sudoku.loadFromIntMatrix(problem);
    bool result = sudoku.fullSolve();
    if(!result) {
        cout << "Algorithm couldn't solve this problem\n";
        sudoku.getDisplayString(true);
    }
    else cout << sudoku.getDisplayString();
    return 0;
}
