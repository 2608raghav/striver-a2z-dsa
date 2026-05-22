/*
Problem: Rat in a Maze
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use Depth First Search (DFS) to explore the maze and find all possible paths from the source to the destination.
2. We will define a helper function `dfs` that takes the current position in the maze and the path taken so far.
3. The `dfs` function will check if the current position is the destination. If it is, we will add the path to the result. If not, we will explore all 4 possible directions (down, left, right, up) from the current position, ensuring that we stay within the bounds of the maze and only move to cells that are open (i.e., have a value of 1).
4. We will also mark the current cell as visited to avoid cycles and backtrack after exploring each direction.

Time Complexity: O(4^(n*m)) in the worst case, where n and m are the dimensions of the maze. This is because in the worst case, we may explore all 4 directions from each cell, leading to an exponential number of paths.
Space Complexity: O(n*m) due to the recursive call stack in the worst case when we explore all cells in the maze. Additionally, we use O(1) space for marking visited cells since we modify the maze in place.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& maze, int i, int j, string path, vector<string>& result) {
        int n = maze.size();
        int m = maze[0].size();

        // If we reach the destination
        if (i == n - 1 && j == m - 1) {
            result.push_back(path);
            return;
        }

        // Mark the cell as visited
        maze[i][j] = 0;

        // Explore all 4 directions
        if (i + 1 < n && maze[i + 1][j] == 1) {
            dfs(maze, i + 1, j, path + 'D', result);
        }
        if (j - 1 >= 0 && maze[i][j - 1] == 1) {
            dfs(maze, i, j - 1, path + 'L', result);
        }
        if (j + 1 < m && maze[i][j + 1] == 1) {
            dfs(maze, i, j + 1, path + 'R', result);
        }
        if (i - 1 >= 0 && maze[i - 1][j] == 1) {
            dfs(maze, i - 1, j, path + 'U', result);
        }

        // Backtrack: unmark the cell
        maze[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>>& maze) {
        vector<string> result;
        if (maze.empty() || maze[0].empty() || maze[0][0] == 0)
            return result; // No paths if starting cell is blocked

        dfs(maze, 0, 0, "", result);
        sort(result.begin(), result.end()); // Sort the results lexicographically
        return result;
    }
};

