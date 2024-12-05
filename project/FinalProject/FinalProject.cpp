/*
Oscar Reyes-Sanchez
CSCI 240
Final Project
Maze Solver using two frameworks (stack/queue, queue/array)
Might include test for optimal path
*/
#include <iostream>
#include "Queue.h"
#include "Maze.h"


using namespace std;



int main()
{
	int square_size = 10;

	cout << "Testing...!\n" << "enter maze size (square): \n";

	cin >> square_size;
	Maze maze(square_size,square_size);

	maze.createMaze();
	maze.displayMaze();
	maze.remakeMaze();
	maze.displayMaze();
	

	cout << "\nAll done !!\n\n\n\n"; // lots of space for my output window
	return 0;
}