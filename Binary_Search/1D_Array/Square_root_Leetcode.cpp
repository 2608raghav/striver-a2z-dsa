/*
Problem: Square Root
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning (0) and one at the end (x) of the search space.
2. Calculate the middle index and its square.
3. If the square of the middle index is equal to x, return the middle index as the square root.
4. If the square of the middle index is less than x, move the start pointer to mid + 1 to search in the right half.
5. If the square of the middle index is greater than x, move the end pointer to mid - 1 to search in the left half.

Time Complexity: O(log x) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the square root is found at the middle index), the time complexity is O(1).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1){
            return x;
        }
        int start = 0;
        int end = x;
        while(start<=end){
            int mid = start + (end - start) / 2;
            long long square = (long long)mid*mid; // Use long long to avoid overflow
            if(square == x){
                return mid;
            }
            else if(square < x){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return end; 
    }
};
