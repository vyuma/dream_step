#include <iostream>
#include <stack>
using namespace std;

const int SIZE = 9;

// Function to display the maze
void display(char arr[SIZE][SIZE]) {
    cout << endl << "= = = = = = = = = = = " << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << "= ";
        for(int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "= " << endl;
    }
    cout << "= = = = = = = = = = = " << endl;
    return;
}

// Function to display the final path
void displayFinal(char arr[SIZE][SIZE]) {
    cout << endl << "Path:" << endl;
    cout << "= = = = = = = = = = = ";
    for(int i = 0; i < SIZE; i++) {
        cout << endl << "= ";
        for(int j = 0; j < SIZE; j++) {
            if (arr[i][j] == 'X')
                cout << "  ";
            else
                cout << arr[i][j] << " ";
        }
        cout << "= ";
    }
    cout << endl << "= = = = = = = = = = = " << endl;
    return;
}

// Check if position is within maze boundaries
bool withinTheBoundary(int i, int j) {
    return i >= 0 && i < SIZE && j >= 0 && j < SIZE;
}

// Define a structure to represent a position in the maze
struct Position {
    int row;
    int col;
    
    Position(int r, int c) : row(r), col(c) {}
};

// Find start and goal positions
Position findPosition(char maze[SIZE][SIZE], char target) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(maze[i][j] == target) {
                return Position(i, j);
            }
        }
    }
    // Default return (should never reach here if maze is valid)
    return Position(-1, -1);
}

// The recursive function to find a path in the maze
// Returns true if a path is found, false otherwise
bool findPath(char maze[SIZE][SIZE], int row, int col, stack<Position>& path) {
    // Check if out of bounds or hitting a wall or visited cell
    if (!withinTheBoundary(row, col) || maze[row][col] == 'W' || maze[row][col] == 'X') {
        return false;
    }
    
    // Check if we've reached the goal
    if (maze[row][col] == 'G') {
        // Add the goal position to our path
        path.push(Position(row, col));
        return true;
    }
    
    // If it's not the start position, mark as visited
    if (maze[row][col] != 'S') {
        maze[row][col] = 'X'; // Mark as visited
    }
    
    // Try to move in all four directions (up, right, down, left)
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];
        
        // Recursive call to explore this direction
        if (findPath(maze, newRow, newCol, path)) {
            // This direction leads to the goal, add current position to path
            path.push(Position(row, col));
            return true;
        }
    }
    
    // If we get here, no path was found from this cell
    return false;
}

// Function to mark the path in the maze
void markPath(char maze[SIZE][SIZE], stack<Position>& path) {
    // Create a copy of the path stack
    stack<Position> pathCopy = path;
    
    // Mark each position in the path with 'o', except start and goal
    while (!pathCopy.empty()) {
        Position pos = pathCopy.top();
        pathCopy.pop();
        
        if (maze[pos.row][pos.col] != 'S' && maze[pos.row][pos.col] != 'G') {
            maze[pos.row][pos.col] = 'o';
        }
    }
}

int main() {
    char maze2D[SIZE][SIZE] = {
        {'S', ' ', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
        {' ', 'W', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'W', 'W', ' ', ' ', 'W', ' '},
        {'W', ' ', 'W', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'W', ' ', ' ', 'W', ' ', ' ', ' '},
        {' ', 'W', ' ', ' ', ' ', ' ', 'W', ' ', 'W'},
        {' ', 'W', ' ', 'W', ' ', ' ', 'W', ' ', ' '},
        {' ', ' ', ' ', 'W', 'W', 'W', ' ', ' ', 'W'},
        {' ', ' ', ' ', ' ', ' ', 'W', ' ', ' ', 'G'},
    };
    
    // Display the original maze
    cout << "Original Maze:" << endl;
    display(maze2D);
    
    // Find the starting position
    Position start = findPosition(maze2D, 'S');
    
    // Stack to store the path
    stack<Position> path;
    
    // Find a path from start to goal
    bool pathFound = findPath(maze2D, start.row, start.col, path);
    
    if (pathFound) {
        // Mark the path in the maze
        markPath(maze2D, path);
        
        // Display the maze with the path
        cout << "\nMaze with path found:" << endl;
        display(maze2D);
        
        // Display the final path (hiding 'X' marks)
        displayFinal(maze2D);
    } else {
        cout << "No path found!" << endl;
    }
    
    return 0;
}