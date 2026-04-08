/*
Problem: Find row with maximum 1s
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. We can use binary search to find the first occurrence of 1 in each row of the matrix.
2. We will iterate through each row of the matrix and perform binary search to find the index of the first occurrence of 1.
3. We will keep track of the maximum number of 1s found and the corresponding row index.
4. Finally, we will return the row index with the maximum number of 1s.

Time Complexity: O(m log n) where m is the number of rows and n is the number of columns in the matrix. We are performing binary search on each row.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code here
        int max_row_index = -1;
        int max_ones = 0;
        
        for(int i=0; i<n; i++){
            int low = 0;
            int high = m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(arr[i][mid] == 1){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            int ones_count = m - low; // Number of 1s in the current row
            if(ones_count > max_ones){
                max_ones = ones_count;
                max_row_index = i;
            }
        }
        return max_row_index;
    }
};