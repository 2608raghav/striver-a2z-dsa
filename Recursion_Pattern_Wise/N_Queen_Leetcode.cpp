/*
Problem: N-Queens
Platform: LeetCode
Topic: Recursion

Approach:
1. We will use backtracking to explore all possible placements of queens on the board.
2. We will define a helper function that takes the current row, the current board configuration, and a vector to store the results.
3. The helper function will iterate through each column in the current row and check if placing a queen in that column is safe (i.e., it does not lead to any conflicts with previously placed queens).
4. If it is safe, we will place the queen and recursively call the helper function for the next row.
5. After exploring all possibilities for the next row, we will backtrack by removing the queen from the current column and continue checking the next columns in the current row.
Time Complexity: O(N!) in the worst case, where N is the number of queens. This is because in the worst case, we may have to explore all possible placements of queens on the board.
Space Complexity: O(N) due to the recursive call stack, which can go up to N levels deep in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void solveNQueensUtil(int row, vector<string>& board, vector<vector<string>>& result) {
        int n = board.size();
        
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q'; // Place queen
                solveNQueensUtil(row + 1, board, result); // Recur to place next queen
                board[row][col] = '.'; // Backtrack
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); // Initialize the board
        
        solveNQueensUtil(0, board, result);
        
        return result;
    }
};


