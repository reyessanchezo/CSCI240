/*
Oscar Reyes-Sanchez
CSCI 240
Final Project
Maze Solver using two frameworks (stack, queue, array)
*/
#include <iostream>
#include "Maze.h"
#include <chrono>  // timing
using namespace std;



int main()
{
	int square_size = -1;
	int go = 0;
	bool sol = false;

	cout << "Testing...!\nDemo first, then loops and timing\n";
	cout << "enter maze size (square): \n";
	cin >> square_size;

	while (square_size < 1) {
		cout << "must be greater than 0\n";
		cin >> square_size;
	}
	Maze maze(square_size, square_size);

	maze.createMaze();
	maze.displayMaze();

	maze.solveMazeBFS();
	cout << "new maze? 1 for yes, 0 for no(exit): ";
	cin >> go;

	while (go == 1)
	{
		while (!sol)
		{
			maze.remakeMaze();
			maze.displayMaze();
			cout << "\n resetting until solvable...\n";
			sol = maze.solveMazeBFS();
		}

		cout << "Now that a solvable maze has been found, solve it with queue, then with stack and compare speeds." <<
			'\n';

		// time the queue framework
		auto start = chrono::high_resolution_clock::now();
		sol = maze.solveMazeBFS();
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> queueDuration = end - start;
		cout << "Time taken by queue: " << queueDuration.count() << " seconds" << '\n';

		// time the stack framework
		start = chrono::high_resolution_clock::now();
		sol = maze.solveMazeDFS();
		end = chrono::high_resolution_clock::now();
		chrono::duration<double> stackDuration = end - start;
		cout << "Time taken by stack: " << stackDuration.count() << " seconds" << '\n';

		cout << "new maze? 1 for yes, 0 for no(exit): ";
		cin >> go;
		sol = false;
	}

	cout << "\nAll done !!\n\n\n\n"; // lots of space for my output window
	return 0;
}