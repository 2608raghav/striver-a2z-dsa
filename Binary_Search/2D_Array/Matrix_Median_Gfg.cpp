/*
Problem: Find the median in a row-wise sorted matrix
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. We can use binary search to find the median in a row-wise sorted matrix.
2. We will first find the minimum and maximum elements in the matrix to define our search space for the median.
3. We will then perform binary search on the range of values from minimum to maximum.
4. For each mid value, we will count how many elements in the matrix are less than or equal to mid.
5. If the count is less than or equal to half of the total number of elements in the matrix, then we need to search for a larger value, so we will move the low pointer up.
6. If the count is greater than half of the total number of elements in the matrix, then we need to search for a smaller value, so we will move the high pointer down.

Time Complexity: O(32 * m * log n) where m is the number of rows and n is the number of columns in the matrix. We are performing binary search on the range of values (which can be at most 32 bits for integers) and counting elements less than or equal to mid takes O(m * log n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid){
        int count = 0;
        for(int i=0; i<matrix.size(); i++){
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return count;
    }
    
    int median(vector<vector<int>> &matrix, int r, int c){
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i=0; i<r; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][c-1]);
        }
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);
            
            if(count <= (r * c) / 2){
                low = mid + 1; // Search in the upper half
            }
            else{
                high = mid - 1; // Search in the lower half
            }
        }
        return low; // The median value
    }
};

