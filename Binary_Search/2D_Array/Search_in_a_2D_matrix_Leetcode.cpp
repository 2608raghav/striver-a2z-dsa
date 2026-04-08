/*
Problem: Search in a 2D Matrix
Platform: Leetcode
Topic: Binary Search

Approach:
1. We can treat the 2D matrix as a 1D sorted array and perform binary search on it.
2. We will calculate the middle index of the 1D representation and convert it back to 2D indices to access the elements in the matrix.
3. We will compare the target element with the middle element of the matrix.

Time Complexity: O(log(m * n)) where m is the number of rows and n is the number of columns in the matrix. We are performing binary search on the entire matrix.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = m * n - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int mid_value = matrix[mid / n][mid % n]; // Convert mid to 2D indices
            
            if(mid_value == target){
                return true;
            }
            else if(mid_value < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false; // Target not found
    }
};