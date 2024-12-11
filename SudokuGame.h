#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H

#include "SudokuGrid.h"
#include <string>
using namespace std;

class SudokuGame {
private:
    SudokuGrid sudokuGrid;
    int chances;
    bool firstwrong;
    void printMessage(const string& message, const string& color) const;

public:
    SudokuGame();
    void startGame();

};

#endif // SUDOKUGAME_H
