#include "sudoku.h"
#include <bitset>

bool Sudoku::singleint(uint16_t i)
{
    return __builtin_popcount(i) == 1;
}

uint16_t Sudoku::posOfSetBit(uint16_t i)
{
    uint16_t ret = 0;
    while(i >>= 1) ret++;
    return ret;
}

void Sudoku::forEachPoint(std::function<void (int, int)> doit)
{
    for(int i = 0; i<9; i++) for(int j = 0; j<9; j++) doit(i, j);
}

uint16_t Sudoku::sumRow(uint16_t row)
{
    uint16_t sum = 0;
    for (int i = 0; i<9; i++) {
        sum += solution[row][i];
    }
    return sum;
}

uint16_t Sudoku::sumCol(uint16_t col)
{
    uint16_t sum = 0;
    for (int i = 0; i<9; i++) {
        sum += solution[i][col];
    }
    return sum;
}

uint16_t Sudoku::sumSquare(uint16_t x, uint16_t y)
{
    uint16_t sum = 0;
    for (int i = x*3; i < x*3+3; i++) {
        for(int j = y*3; j < y*3+3; j++){
            sum += solution[i][j];
        }
    }
    return sum;
}

Sudoku::Sudoku(): solution{}{}

void Sudoku::loadFromIntMatrix(int **schema)
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(schema[i][j] == 0) possiblities.insert(std::make_pair(std::make_pair(i, j), 0));
            else solution[i][j] = (1 << (schema[i][j]-1));
        }
    }
}

std::string Sudoku::getDisplayString(bool extended)
{
    std::string ret = "";
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(singleint(solution[i][j])){
                ret += std::to_string(posOfSetBit(solution[i][j]));
            } else{
                ret += " ";
            }

            if(j % 3 == 2 && j != 8){
                ret += "|";
            }
        }
        ret += "\n";
        if(i % 3 == 2 && i != 8){
            ret += "---+---+---\n";
        }
    }
    if(!extended) return ret;
    ret += "\nPossible values:\n";
    for(auto empty : possiblities){
        ret += "(" + std::to_string(empty.first.first + 1) + ", " + std::to_string(empty.first.second + 1) + "): " + std::bitset<9>(empty.second).to_string() + "\n";
    }
    return ret;
}

bool Sudoku::fullSolve()
{
    auto oldPossiblites = possiblities;
    do{
        bool empty = iterate();
        if(!empty) return true;
    } while(oldPossiblites != possiblities);
    return false;
}

bool Sudoku::iterate()
{
    bool foundEmpty = false;
    forEachPoint([&](int row, int col){
        if(solution[row][col] != 0) return;
        uint16_t alreadyExists = sumRow(row) | sumCol(col) | sumSquare(row/3, col/3);
        uint16_t possibleValues = 0b0000'0001'1111'1111 ^ alreadyExists;
        if(singleint(possibleValues)){
            solution[row][col] = possibleValues;
        } else{
            possiblities[std::make_pair(row, col)] = possibleValues;
        }
        foundEmpty = true;
    });
    return foundEmpty;
}
