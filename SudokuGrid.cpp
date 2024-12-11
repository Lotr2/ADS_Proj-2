#include "SudokuGrid.h"

SudokuGrid::SudokuGrid(int gridSize) {
    size = gridSize;
    subgrid_size = sqrt(size);
    grid = vector<vector<int>>(size, vector<int>(size, 0));
    solution = vector<vector<int>>(size, vector<int>(size, 0));
}

int SudokuGrid::getValue(int r, int c) {
    return grid[r][c];
}

bool SudokuGrid::isValid(int row, int col, int num) const {
    for (int c = 0; c < size; ++c) {
        if (grid[row][c] == num) return false;
    }
    for (int r = 0; r < size; ++r) {
        if (grid[r][col] == num) return false;
    }
    int startRow = row - row % subgrid_size;
    int startCol = col - col % subgrid_size;
    for (int r = startRow; r < startRow + subgrid_size; ++r) {
        for (int c = startCol; c < startCol + subgrid_size; ++c) {
            if (grid[r][c] == num) return false;
        }
    }
    return true;
}

bool SudokuGrid::solveSudoku() {
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= size; ++num) {
                    if (isValid(row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku()) return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void SudokuGrid::generatePuzzle(int clues) {
    solveSudoku();
    solution = grid;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, size - 1);

    int cellsToRemove = size * size - clues;
    while (cellsToRemove > 0) {
        int row = dist(gen);
        int col = dist(gen);
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            --cellsToRemove;
        }
    }
}

bool SudokuGrid::checkUserInput(int row, int col, int num) const {
    return solution[row][col] == num;
}

void SudokuGrid::setValue(int row, int col, int num) {
    grid[row][col] = num;
}

void SudokuGrid::display() const {
    for (int row = 0; row < size; ++row) {
        if (row % subgrid_size == 0 && row != 0) {
            cout << string(size * 2 + subgrid_size - 1, '-') << endl;
        }
        for (int col = 0; col < size; ++col) {
            if (col % subgrid_size == 0 && col != 0) {
                cout << "| ";
            }
            cout << (grid[row][col] == 0 ? '.' : char('0' + grid[row][col])) << " ";
        }
        cout << endl;
    }
}

bool SudokuGrid::isComplete() const {
    for (const auto& row : grid) {
        for (int num : row) {
            if (num == 0) return false;
        }
    }
    return true;
}
vector<vector<int> > SudokuGrid::getGrid() {
    return grid;
}

