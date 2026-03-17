/*
Problem: Spiral Matrix
Platform: LeetCode
Topic: Array

Approach:
1. We can use four pointers to keep track of the boundaries of the matrix: "top", "bottom", "left", and "right".
2. Initialize "top" to 0, "bottom" to the last index of the rows, "left" to 0, and "right" to the last index of the columns.
3. Use a while loop that continues until the size of the result vector is equal to the total number of elements in the matrix (row * column).
4. Inside the loop, perform the following steps in order:
   - Traverse from left to right along the "top" row and add elements to the result vector. Then increment "top" to move down to the next row.
   - Traverse from top to bottom along the "right" column and add elements to the result vector. Then decrement "right" to move left to the next column.
   - If "top" is still less than or equal to "bottom", traverse from right to left along the "bottom" row and add elements to the result vector. Then decrement "bottom" to move up to the next row.
   - If "left" is still less than or equal to "right", traverse from bottom to top along the "left" column and add elements to the result vector. Then increment "left" to move right to the next column.
5. Repeat this process until all elements have been added to the result vector in spiral order.

Time Complexity: O(n) since we need to iterate through the array once to shift the elements.
Space Complexity: O(1) as we are using only a constant amount of extra space to

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int top =0;
        int bottom =row-1;
        int left = 0;
        int right =column-1;
        vector<int>res;
        
        while(true){
            if(res.size()!=(row*column)){
            // left->right
            for(int i=left;i<=right;i++){
               res.push_back(matrix[top][i]);
            }
            top++;
            // top -> bottom
            for(int i=top;i<=bottom;i++){
                res.push_back(matrix[i][right]);
                }
                right--;
                // right -> left
                if(top<=bottom){
               for(int i=right;i>=left;i--){
                   res.push_back(matrix[bottom][i]);
               }
               bottom--;
                }
               // bottom -> top
               if(left<=right){
               for(int i=bottom;i>=top;i--){
                   res.push_back(matrix[i][left]);
               }
               left++;
               }
            }
            else{
                return res;
            }
        }
        return res;
    }
};