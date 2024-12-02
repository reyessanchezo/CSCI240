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



int main()
{
    cout << "Testing...!\n creating maze";

	const int rows = 5;
    const int cols = 5;

    Maze maze(rows, cols);
    
    cout << "Created\n";

    cout << "All done !!\n";
    return 0;
}

