/*
Problem: Search in a 2D Matrix II
Platform: Leetcode
Topic: Binary Search

Approach:
1. We can perform binary search on each row of the matrix to find the target element.
2. We will iterate through each row of the matrix and perform binary search to check if the target element exists in that row.
3. If we find the target element in any row, we can return true. If we finish checking all rows and do not find the target element, we will return false.

Time Complexity: O(m log n) where m is the number of rows and n is the number of columns in the matrix. We are performing binary search on each row.
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
        
        for(int i=0; i<m; i++){
            int low = 0;
            int high = n - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] < target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false; // Target not found in any row
    }
};
