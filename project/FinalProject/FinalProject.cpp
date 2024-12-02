/*
Oscar Reyes-Sanchez
CSCI 240
Final Project
Maze Solver using two frameworks (stack/queue, queue/array)
Might include test for optimal path
*/
#include <iostream>
#include "Maze.h"

using namespace std;

#define ROWS = 5;
#define COLS = 5;

int main()
{
    cout << "Testing...!\n creating maze";

    Maze::Maze(ROWS, COLS);
    cout << "Created\n";

    cout << "All done !!\n";
    return 0;
}

