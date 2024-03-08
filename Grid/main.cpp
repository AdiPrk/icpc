#pragma warning(disable : 6031) // annoying scanf warning
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Does a breadth first search algorithm.
// Idk how good this code is, i suck at graph stuff

struct Cell {
    int x, y;
};

// BFS takes in a grid, returns steps to get to the end of the grid
int BFS(const vector<vector<int>>& grid, int m, int n) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<Cell, int>> q; // Queue to store cell and its steps from the start

    // Directions: up, right, down, left
    vector<Cell> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    // Start from the top-left corner
    q.push({ {0, 0}, 0 }); //cell, int
    visited[0][0] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Cell cell = front.first;
        int steps = front.second;

        // Check if we've reached the bottom-right corner
        if (cell.x == m - 1 && cell.y == n - 1) {
            return steps;
        }

        // Explore all 4 possible moves from the current cell
        for (const auto& dir : directions) {
            int newX = cell.x + dir.x * grid[cell.x][cell.y]; // x + cell `k` * direction
            int newY = cell.y + dir.y * grid[cell.x][cell.y];

            // Check if the new position is within the grid bounds and not visited
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({ {newX, newY}, steps + 1 });
            }
        }
    }

    // If the bottom-right corner is not reached, return IMPOSSIBLE
    return -1;
}

int main() {
    freopen("../input.txt", "r", stdin);

    // apparently speeds up io operations //
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ---------------------------------- //

    // Input
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n)); // m x n grid

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = ch - '0'; // Convert char digit to int
        }
    }

    // Algorithm
    int result = BFS(grid, m, n);

    // Output
    if (result == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << result << endl;
    }

    fclose(stdin);
    return 0;
}
