#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <vector>
#include <cmath>
#include <iostream>
#include <random>
using namespace std;

class SudokuGrid {
private:
    vector<vector<int>> grid; // Represents the main Sudoku grid
    vector<vector<int>> solution; // Stores the solved version of the Sudoku grid
    int size; // The overall size of the Sudoku grid (e.g., 9 for a 9x9 grid)
    int subgrid_size; // The size of the subgrids (e.g., 3 for a standard 9x9 Sudoku)

public:
    SudokuGrid(int gridSize = 9); // Initializes a Sudoku grid with a default size of 9x9
    bool isValid(int row, int col, int num) const; // Checks if placing a number in a specific cell is valid
    bool solveSudoku(); // Attempts to solve the Sudoku grid using backtracking
    void generatePuzzle(int clues); // Generates a Sudoku puzzle with a specified number of initial clues
    bool checkUserInput(int row, int col, int num) const; // Verifies whether a user's input follows Sudoku rules
    void setValue(int row, int col, int num); // Sets a specific value in the Sudoku grid
    int getValue(int r, int c); // Retrieves the value from a specific cell in the grid
    void display() const; // Prints the current state of the Sudoku grid to the console
    bool isComplete() const; // Checks if the Sudoku grid is fully and correctly solved
    vector<vector<int>> getGrid(); // Returns the current state of the Sudoku grid
};

#endif // SUDOKUGRID_H