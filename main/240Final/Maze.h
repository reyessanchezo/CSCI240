#ifndef MAZE_H
#define MAZE_H

#include <iostream>

class Maze {
private:
    int** maze;
    int rows;
    int cols;

public:
    // Constructor to initialize the maze with given dimensions
    Maze(int r, int c);
    Maze();
    Maze(Maze* maze);

    // Destructor to free allocated memory
    ~Maze();

    // Function to create a random maze
    void createMaze() const;

    // Function to display the maze
    void displayMaze() const;

    // Function to set a specific cell in the maze
    void setCell(int r, int c, int value) const;

    // Function to get the value of a specific cell in the maze
    int getCell(int r, int c) const;
};

#endif // MAZE_H
