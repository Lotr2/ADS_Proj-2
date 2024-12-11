#include "SudokuGame.h"
#include <iostream>
using namespace std;

SudokuGame::SudokuGame() : sudokuGrid(9), chances(5), firstwrong(false) {}

void SudokuGame::printMessage(const string& message, const string& color) const {
    cout << message << endl;
}

void SudokuGame::startGame() {
    int clues = 17;

    cout << "You stand at the fiery chasm of Mount Doom. The One Ring, forged by Sauron in the depths of Mordor, lies in your grasp.\n";
    cout << "The Eye of Sauron glares down upon you, a searing gaze that pierces the soul. Solve this Sudoku puzzle to complete your quest and cast the Ring into the flames!\n";
    cout << "The fate of the Free Peoples is in your hands...\n";

    sudokuGrid.generatePuzzle(clues);
    cout << "\n";

    while (!sudokuGrid.isComplete()) {
        sudokuGrid.display();

        int row, col, num;
        cout << "Enter your move (row col num): ";
        cin >> row >> col >> num;
        row--;
        col--;

        if (row < 0 || col < 0 || row >= 9 || col >= 9 || num < 1 || num > 9) {
            printMessage("Invalid input. Try again.", "red");
            continue;
        }

        if (sudokuGrid.getValue(row, col) == 0) {
            if (sudokuGrid.checkUserInput(row, col, num)) {
                printMessage("Good job, Frodo!", "green");
                sudokuGrid.setValue(row, col, num);
            } else {
                if (!firstwrong) {
                    printMessage("You have made a mistake", "red");
                    printMessage("As your grip falters, the Ring wavers on the brink of the fiery chasm. The Eye of Sauron flares, a searing reminder of what is at stake.", "yellow");
                    printMessage("You hear a distant voice. It reminds you of why you are here", "yellow");
                    printMessage("\"Don't give up, Frodo! Hope remains, even in the shadow of doubt.\"", "green");
                    printMessage("5 chances remaining.", "yellow");
                    firstwrong = true;
                } else {
                    printMessage("Wrong.", "red");
                    chances--;
                    cout << chances << " chances remaining." << endl;
                    if (chances == 0) {
                        break;
                    }
                }
            }
        } else {
            printMessage("Box already has a value. Choose another.", "yellow");
        }
    }

    if (chances != 0) {
        printMessage("Congratulations! You solved the Sudoku!", "green");
        sudokuGrid.display();
    } else {
        printMessage("You have failed. There is no future for Middle-earth.", "red");
    }
}
