#include "Maze.h"
#include <ctime>
#include <cstdlib>
using namespace std;

// Constructor to initialize the maze with given dimensions
Maze::Maze(int r, int c) : rows(r), cols(c) {
    maze = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        maze[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            maze[i][j] = 0; // Initialize all cells to 0
        }
    }
}

// Destructor to free allocated memory
Maze::~Maze() {
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }
    delete[] maze;
}

// Function to create a random maze
void Maze::createMaze() const
{
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = rand() % 2; // Randomly assign 0 or 1
        }
    }
    maze[0][0] = 0; // Ensure start point is open
    maze[rows - 1][cols - 1] = 0; // Ensure end point is open
}

// Function to display the maze
void Maze::displayMaze() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << (maze[i][j] == 1 ? "#" : ".") << " ";
        }
        std::cout << endl;
    }
}

// Function to set a specific cell in the maze
void Maze::setCell(int r, int c, int value) const
{
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        maze[r][c] = value;
    }
}

// Function to get the value of a specific cell in the maze
int Maze::getCell(int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        return maze[r][c];
    }
    return -1; // Return -1 if out of bounds
}
