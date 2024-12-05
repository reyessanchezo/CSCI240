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
	int square_size = 10;
	int go = 1;

	cout << "Testing...!\n" << "enter maze size (square): \n";

	cin >> square_size;
	Maze maze(square_size, square_size);

	maze.createMaze();
	maze.displayMaze();

	maze.solveMazeBFS();
	cout << "new maze? 1 for yes, 0 for no(exit): ";
	cin >> go;

	while (go == 1)
	{
		cout << "enter new maze size (square) ";
		cin >> square_size;
		Maze new_maze(square_size, square_size);

		maze.createMaze();
		maze.displayMaze();
		cout << "\n solving...\n";
		maze.solveMazeBFS();
		cout << "new maze? 1 for yes, 0 for no(exit): ";
		cin >> go;
	}

	cout << "\nAll done !!\n\n\n\n"; // lots of space for my output window
	return 0;
}