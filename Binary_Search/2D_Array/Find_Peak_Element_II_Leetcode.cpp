/*
Problem: Find Peak Element II
Platform: Leetcode
Topic: Binary Search

Approach:
1. We can use binary search to find a peak element in the 2D matrix.
2. We will start by finding the middle column of the matrix and then find the maximum element in that column.
3. We will compare the maximum element with its left and right neighbors (if they exist).
4. If the maximum element is greater than its neighbors, then it is a peak element and we can return its position.
5. If the left neighbor is greater than the maximum element, then there must be a peak element in the left half of the matrix, so we will continue our search in the left half.
6. If the right neighbor is greater than the maximum element, then there must be a peak element in the right half of the matrix, so we will continue our search in the right half.

Time Complexity: O(m log n) where m is the number of rows and n is the number of columns in the matrix. We are performing binary search on the columns and finding the maximum element in each column takes O(m) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int max_row_index = 0;
            for(int i=1; i<m; i++){
                if(mat[i][mid] > mat[max_row_index][mid]){
                    max_row_index = i;
                }
            }
            
            bool left_is_smaller = (mid == 0) || (mat[max_row_index][mid] > mat[max_row_index][mid - 1]);
            bool right_is_smaller = (mid == n - 1) || (mat[max_row_index][mid] > mat[max_row_index][mid + 1]);
            
            if(left_is_smaller && right_is_smaller){
                return {max_row_index, mid}; // Peak element found
            }
            else if(!left_is_smaller){
                high = mid - 1; // Search in the left half
            }
            else{
                low = mid + 1; // Search in the right half
            }
        }
        return {-1, -1}; // This line should never be reached as there is always a peak element
    }
};

