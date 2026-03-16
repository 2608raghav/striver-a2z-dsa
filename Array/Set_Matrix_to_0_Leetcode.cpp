/*
Problem: Set Matrix to Zeroes
Platform: LeetCode
Topic: Array

Approach:
1. Create a vector "store" to keep track of the positions of all elements that are 0 in the matrix.
2. Traverse the entire matrix using two nested loops.
3. Whenever a 0 is found at position (i, j), store its row and column indices in the vector.
   - First push the row index i.
   - Then push the column index j.
4. After collecting all positions of zero elements, iterate through the "store" vector in steps of 2.
5. For each stored position (row, column):
   - Traverse the entire row and set every element in that row to 0.
   - Traverse the entire column and set every element in that column to 0.
6. By repeating this process for all stored positions, every row and column that originally contained a 0 becomes filled with zeros.

Time Complexity: O((N*M) + K*(N+M))
- O(N*M) for scanning the entire matrix to find zeros.
- O(K*(N+M)) for updating rows and columns, where K is the number of zeros found.

Space Complexity: O(K) where K is the number of zeros stored in the vector.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> store;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    store.push_back(i);
                    store.push_back(j);
                }
            }
        }

        int row = 0;
        int column = 0;

        for(int i = 0; i < store.size(); i = i + 2){
            row = store[i];
            column = store[i+1];

            // set entire row to 0
            for(int j = 0; j < matrix[row].size(); j++){
                matrix[row][j] = 0;
            }

            // set entire column to 0
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][column] = 0;
            }
        }
    }
};