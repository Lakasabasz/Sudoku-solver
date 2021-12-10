#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
#include <map>
#include <cstdint>
#include <functional>

class Sudoku
{
private:
    uint16_t solution[9][9];
    std::map<std::pair<int, int>, uint16_t> possiblities;

    bool singleint(uint16_t);
    uint16_t posOfSetBit(uint16_t);

    void forEachPoint(std::function<void(int, int)> doit);

    uint16_t sumRow(uint16_t row);
    uint16_t sumCol(uint16_t col);
    uint16_t sumSquare(uint16_t x, uint16_t y);

public:
    Sudoku();
    void loadFromIntDynamicMatrix(int** schema);
	void loadFromIntMatrix(int schema[9][9]);
    std::string getDisplayString(bool extended = false);

    bool fullSolve();
    bool iterate();
};

#endif // SUDOKU_H
