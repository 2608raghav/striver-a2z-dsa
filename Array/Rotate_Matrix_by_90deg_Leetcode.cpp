/*
Problem: Rotate Matrix by 90 degrees
Platform: Leetcode
Topic: Array

Approach:
1. The matrix needs to be rotated by 90 degrees clockwise in-place.
2. Instead of creating another matrix, we use a two-step transformation.
3. Step 1: Transpose the matrix.
   - In transpose, rows become columns.
   - Swap matrix[i][j] with matrix[j][i] for all i < j.
   - This converts the matrix across its main diagonal.
4. Step 2: Reverse each row of the matrix.
   - After transpose, reverse every row individually.
   - This shifts the elements to their correct rotated positions.
5. After these two steps, the matrix becomes the 90° clockwise rotation
   of the original matrix.

Time Complexity: O(n) since we need to iterate through the array once to shift the elements.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the temporary variable.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       // 1) Transpose of the matrix
       // 2) Reverse the each row
       for(int i=0;i<matrix.size()-1;i++){
        for(int j=i+1;j<matrix.size();j++){
            swap( matrix[i][j],matrix[j][i]);
        }
       }
       for(int i=0;i<matrix.size();i++){
        reverse(matrix[i].begin(),matrix[i].end());
       }
    }
};