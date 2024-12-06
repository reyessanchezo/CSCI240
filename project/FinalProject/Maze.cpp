#include "Maze.h"
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Queue.h"
using namespace std;

// Constructor to initialize the maze with given dimensions
Maze::Maze(int r, int c) : rows(r), cols(c)
{
	maze = new int*[rows];
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

	maze = new int*[rows];
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

// Destructor to free allocated memory
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
	srand(time(0));
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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			maze[i][j] = NULL; // Reset every cell
		}
	}
	this->createMaze();
}

// Function to display the maze
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

// Function to set a specific cell in the maze
void Maze::setCell(int r, int c, int value) const
{
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		// bounds
		maze[r][c] = value;
	}
}

// Function to get the value of a specific cell in the maze
int Maze::getCell(int r, int c) const
{
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		return maze[r][c];
	}
	return -1; // Return -1 if out of bounds
}

bool Maze::solveMazeBFS()
{
	Queue queue;
	vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
	queue.Enqueue(0 * cols + 0);
	// Encode cell (0, 0) as a single integer
	visited[0][0] = true;
	while (!queue.IsEmpty())
	{
		int encoded = queue.Dequeue();
		int currentX = encoded / cols;
		int currentY = encoded % cols;
		// Check if reached the destination
		if (currentX == rows - 1 && currentY == cols - 1)
		{
			std::cout << "Maze solved!" << '\n';
			queue.Print();
			return true;
		}
		// Possible directions: right, down, left, up
		int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		for (auto& dir : directions)
		{
			int newX = currentX + dir[0];
			int newY = currentY + dir[1];
			if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && (maze[newX][newY] == 0) && !visited[newX][newY])
			{
				queue.Enqueue(newX * cols + newY);
				
				// Encode new cell
				visited[newX][newY] = true;
				std::cout << "visited [" << newX << "][" << newY << "]" << '\n';
			}
		}
	}
	std::cout << "No solution found." << '\n';
	return false;
}
