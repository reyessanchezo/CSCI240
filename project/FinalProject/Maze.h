#ifndef MAZE_H
#define MAZE_H
#include <iostream>

class Maze {
private:
    int** maze;
    int rows;
    int cols;

public:
    Maze(int r, int c);
    Maze();
    Maze(const Maze* cp_maze);

    ~Maze();

    //  create a random maze
    void createMaze() const;

    void remakeMaze() const;

    void displayMaze() const;

    void setCell(int r, int c, int value) const;

    int getCell(int r, int c) const;

	bool solveMazeBFS() const;

    bool solveMazeDFS() const;
};

#endif // MAZE_H
