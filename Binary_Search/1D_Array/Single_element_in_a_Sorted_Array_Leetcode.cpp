/*
Problem: Single Element in a Sorted Array
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. Check if the middle element is the single element by comparing it with its neighbors.
4. If the middle element is not the single element, determine which half of the array to search next based on the index of the middle element and its relationship with its neighbors.
5. Repeat steps 2-4 until the single element is found.

Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the single element is found at the middle index), the time complexity is O(1).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start =0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if((mid==0 || nums[mid]!=nums[mid-1]) && (mid==nums.size()-1 || nums[mid]!=nums[mid+1])){
                return nums[mid];
            }
            else if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    start=mid+2;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1; 
    }
};
