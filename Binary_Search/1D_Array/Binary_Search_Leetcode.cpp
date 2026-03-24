/*
Problem: Binary Search
Platform: LeetCode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. Compare the target with the element at the middle index.
4. If they are equal, return the middle index.
5. If the target is less than the element at the middle index, search in the left half.
6. If the target is greater than the element at the middle index, search in the right half.
7. Repeat steps 2-6 until the target is found or the pointers cross each other.


Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the array is already sorted), the time complexity is O(log n).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = (start+end)/2;
        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = (start+end)/2;
        }
        return -1;
    
    }
};