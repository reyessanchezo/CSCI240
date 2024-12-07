#include "Maze.h"
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Queue.h"
#include "Stack.h"
using namespace std;

Maze::Maze(int r, int c) : rows(r), cols(c)
{
	maze = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		maze[i] = new int[cols];
		for (int j = 0; j < cols; ++j)
		{
			maze[i][j] = 0; // Initialize all cells to 0
		}
	}
	cout << "Created a " << rows << " by " << cols << " Maze\n";
}

Maze::Maze()
{
	rows = 1;
	cols = 1;

	maze = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		maze[i] = new int[cols];
		for (int j = 0; j < cols; ++j)
		{
			maze[i][j] = 0; // Initialize all cells to 0
		}
	}
}

Maze::Maze(const Maze* cp_maze)
{
	rows = cp_maze->rows;
	cols = cp_maze->cols;
	maze = cp_maze->maze;
}

Maze::~Maze()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] maze[i];
	}
	delete[] maze;
}

// Function to create a random maze
void Maze::createMaze() const
{
	srand(time(nullptr));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			maze[i][j] = rand() % 2; // Randomly assign 0 or 1
		}
	}
	maze[0][0] = 0; // Ensure start point is open
	maze[rows - 1][cols - 1] = 0; // Ensure end point is open
}

void Maze::remakeMaze() const
{
	srand(time(nullptr));
	/*
	srand cause a bit of trouble, especially while waiting
	for the main function to find a solvable maze
	*/

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			maze[i][j] = rand() % 2; // Randomly assign 0 or 1
		}
	}
	maze[0][0] = 0; // Ensure start point is open
	maze[rows - 1][cols - 1] = 0; // Ensure end point is open
}

// display with # as walls and . as open spaces
void Maze::displayMaze() const
{
	std::cout << '\n';
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (i == 0 && j == 0)
			{
				std::cout << "start \t> ";
			}
			else if (i == rows - 1 && j == cols - 1)
			{
				std::cout << "> Exit ";
			}
			else
			{
				std::cout << (maze[i][j] == 1 ? "#" : ".") << " ";
			}
		}
		std::cout << '\n' << '\t';
	}
}

void Maze::setCell(int r, int c, int value) const
{
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		// bounds
		maze[r][c] = value;
	}
}

int Maze::getCell(int r, int c) const
{
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		return maze[r][c];
	}
	return -1; // Return -1 if out of bounds :(
}

bool Maze::solveMazeBFS() const
{
	Queue queue;
	vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
	queue.Enqueue(0 * cols + 0); // store the start point

	visited[0][0] = true;
	while (!queue.IsEmpty())
	{
		int encoded = queue.Dequeue();
		int currentX = encoded / cols;
		int currentY = encoded % cols;
		// Check if reached the destination
		if (currentX == rows - 1 && currentY == cols - 1)
		{
			std::cout << "Maze queue solved!" << '\n';
			return true;
		}
		// try each right, down, left, up
		int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
		for (auto& dir : directions)
		{
			int newX = currentX + dir[0];
			int newY = currentY + dir[1];
			if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && (maze[newX][newY] == 0) && !visited[newX][newY])
			{
				queue.Enqueue(newX * cols + newY);

				// Encode new cell
				visited[newX][newY] = true;
			}
		}
	}
	std::cout << "No queue solution found." << '\n';
	return false;
}

bool Maze::solveMazeDFS() const
{
	Stack stack;
	vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
	stack.Push(0, 0); //push start point
	visited[0][0] = true;
	while (stack.GetLength() > 0)
	{
		int* encoded = stack.Pop();
		int currentX = encoded[0] / cols;
		int currentY = encoded[1] % cols; // extract current coordinates
		// Check if reached the destination
		if (currentX == rows - 1 && currentY == cols - 1)
		{
			std::cout << "Maze stack solved!" << '\n';
			return true;
		}
		// try each right, down, left, up
		int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
		for (auto& dir : directions)
		{
			int newX = currentX + dir[0];
			int newY = currentY + dir[1];
			if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && (maze[newX][newY] == 0) && !visited[newX][newY])
			{
				stack.Push(newX, newY);

				//track visited cells
				visited[newX][newY] = true;
			}
		}
	}
	std::cout << "No stack solution found." << '\n';
	return false;
}