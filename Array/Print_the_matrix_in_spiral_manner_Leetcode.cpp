/*
Problem: Print the matrix in spiral manner
Platform: LeetCode
Topic:  Array

Approach:
1. To print the matrix in spiral order, we can use four pointers to keep track of the boundaries of the matrix: "starting_row", "ending_row", "starting_col", and "ending_col".
2. We can initialize these pointers as follows: "starting_row" = 0, "ending_row" = row - 1, "starting_col" = 0, and "ending_col" = col - 1.
3. We can also maintain a count of the number of elements printed and the total number of elements in the matrix to ensure we do not print more elements than available.
4. We can use a while loop that continues until the count of printed elements is less than the total number of elements in the matrix.
5. Inside the while loop, we can perform the following steps in order:
   a. Print the elements of the "starting_row" from "starting_col" to "ending_col" and increment the "starting_row" pointer.
   b. Print the elements of the "ending_col" from "starting_row" to "ending_row" and decrement the "ending_col" pointer.
   c. Print the elements of the "ending_row" from "ending_col" to "starting_col" and decrement the "ending_row" pointer.
   d. Print the elements of the "starting_col" from "ending_row" to "starting_row" and increment the "starting_col" pointer.

Time Complexity: O(m*n) since we need to print all the elements of the matrix.
Space Complexity: O(1) since we are using only a constant amount of extra space to store the pointers and count variables.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int total = row*col;
        int starting_row = 0;
        int starting_col = 0;
        int ending_row = row-1;
        int ending_col = col-1;

        while(count<total){
            // print starting row
            for(int index = starting_col;count<total && index<=ending_col;index++){
                ans.push_back(matrix[starting_row][index]);
                count++;
            }
            starting_row++;

            // print ending column
            for(int index = starting_row;count<total && index<=ending_row;index++){
                ans.push_back(matrix[index][ending_col]);
                count++;
            }
            ending_col--;

            // print ending row
            for(int index = ending_col;count<total && index>=starting_col;index--){
                ans.push_back(matrix[ending_row][index]);
                count++;
            }
            ending_row--;

            // print starting column
            for(int index = ending_row;count<total && index>=starting_row;index--){
                ans.push_back(matrix[index][starting_col]);
                count++;
            }
            starting_col++;
        }
        return ans;

    }
};


