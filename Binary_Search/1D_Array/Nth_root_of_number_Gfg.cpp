/*
Problem: Nth Root of a Number
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning (0) and one at the number (n) of the search space.
2. Calculate the middle index and its nth power.
3. If the nth power of the middle index is equal to n, return the middle index as the nth root.
4. If the nth power of the middle index is less than n, move the start pointer to mid + 1 to search in the right half.
5. If the nth power of the middle index is greater than n, move the end pointer to mid - 1 to search in the left half.

Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the nth root is found at the middle index), the time complexity is O(1).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int start = 0;
        int end = m;
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(pow(mid,n)==m){
                return mid;
            }
            else if(pow(mid,n)<m){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};
