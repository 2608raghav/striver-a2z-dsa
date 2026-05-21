/*
Problem: Word Search
Platform: LeetCode
Topic: Recursion

Approach:
1. We will use Depth First Search (DFS) to explore the board and check if we can find the given word.
2. We will define a helper function `dfs` that takes the current position on the board and the index of the current character in the word.
3. The `dfs` function will check if the current character matches the character in the word at the given index. If it does, we will mark the cell as visited and recursively explore all 4 adjacent cells (up, down, left, right) for the next character in the word.
4. If we successfully match all characters in the word, we will return true. If we exhaust all possibilities without finding the word, we will return false.

Time Complexity: O(N * 3^L) in the worst case, where N is the number of cells in the board and L is the length of the word. This is because we may explore each cell and for each cell, we have at most 3 directions to explore (since we cannot go back to the previous cell).
Space Complexity: O(L) due to the recursive call stack, which can go up to L levels deep in the worst case when we are matching the characters of the word. Additionally, we use O(1) space for marking visited cells since we modify the board in place.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // If all characters matched
        if (index == word.size()) return true;

        // Boundary + mismatch check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
