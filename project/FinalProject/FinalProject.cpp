/*
Oscar Reyes-Sanchez
CSCI 240
Final Project
Maze Solver using two frameworks (stack/queue, queue/array)
Might include test for optimal path
*/
#include <iostream>

#include "Maze.cpp"

using namespace std;



int main()
{
	cout << "Testing...!\n";

	const int rows = 5;
	const int cols = 5;

	Maze maze(rows,cols);
	maze.createMaze();
	maze.displayMaze();
	

	cout << "All done !!\n\n\n\n"; // lots of space for my output window
	return 0;
}

