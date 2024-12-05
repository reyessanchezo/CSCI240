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
	cout << "Testing...!\n";

	const int rows = 10;
	const int cols = 10;

	Maze maze(rows,cols);
	maze.createMaze();
	maze.displayMaze();
	maze.remakeMaze();
	maze.displayMaze();
	

	cout << "\nAll done !!\n\n\n\n"; // lots of space for my output window
	return 0;
}