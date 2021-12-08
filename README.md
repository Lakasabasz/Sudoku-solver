[🇵🇱 - polska wersja](README-pl.md)

# Sudoku solver
This algorithm solves sudoku 9x9. It was written in C++ using class `Sudoku` which is core of algorithm. Tested on 1 case: 100% correct.

## Installation
To compile you need C++ compiler supports standard 17 and CMake compatible version 3.5.
Commands to run:
```bash
mkdir build
cmake -S . -B build
cmake --build build
```

## Usage
Just find executable and run. On Windows that file name will be ended with `.exe`. If you want to run other examples just edit file `main.cpp` or link `sudoku.h` and `sudoku.cpp` to your project.

Example:
```cpp
#include "sudoku.h"
#include <iostream>

int main(){
  int** data;
  //Load here your data to 2 dimensional dynamic integer array

  Sudoku s();
  s.loadFromIntMatrix(data);
  std::cout << s.fullSolve() << "\n" << s.getDisplayString();
  return 0;
}
```

## Contribution
- **Issues**
If you find any bug or have any idea how to improve it, make issue. I will think about it and maybe I will do it
- **Pull Request**
if you have already working code and you want to share it, I will accept it

## License CC-BY 4.0
Full license [click here](https://creativecommons.org/licenses/by/4.0/deed)
