/*
Problem: Sudoku Solver
Platform: LeetCode
Topic: Recursion

Approach:
1. We will use backtracking to solve the Sudoku puzzle. The idea is to fill the empty cells one by one and check if the current placement is valid.
2. We will define a helper function that takes the current board and the position of the cell we are trying to fill. The function will iterate through the possible numbers (1-9) and check if placing a number in the current cell is valid according to Sudoku rules (i.e., the number does not already exist in the same row, column, or 3x3 subgrid).
3. If placing a number is valid, we will place the number and recursively call the helper function to fill the next cell. If we successfully fill the board, we return true. If we cannot fill the board with the current placement, we will backtrack by resetting the cell and trying the next number.
4. The main function will call the helper function with the initial parameters.

Time Complexity: O(9^(m*n)) in the worst case, where m and n are the dimensions of the board (9x9). This is because in the worst case, we may have to try all 9 numbers for each of the empty cells.
Space Complexity: O(m*n) due to the recursive call stack, which can go up to m*n levels deep in the worst case if all cells are empty. Additionally, we use O(1) space for the board itself since we modify it in place.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num || 
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
                return false;
            }
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') { // Find an empty cell
                    for (char num = '1'; num <= '9'; num++) { // Try numbers 1-9
                        if (isValid(board, row, col, num)) { // Check if it's valid
                            board[row][col] = num; // Place the number
                            
                            if (solveSudoku(board)) { // Recur to fill the next cell
                                return true;
                            }
                            
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found, trigger backtracking
                }
            }
        }
        return true; // All cells are filled successfully
    }
    
    void solve_Sudoku(vector<vector<char>>& board) {
        solveSudoku(board);
    }
};
