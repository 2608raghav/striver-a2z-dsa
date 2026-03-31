/*
Problem: Find Peak Element
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. Compare the middle element with its neighbors (if they exist).
4. If the middle element is greater than its neighbors, it is a peak element. Return the middle index.
5. If the middle element is less than its left neighbor, it means there is a peak element in the left half of the array. Therefore, update the end pointer to mid - 1.
6. If the middle element is less than its right neighbor, it means there is a peak element in the right half of the array. Therefore, update the start pointer to mid + 1.
7. Repeat steps 2-6 until the pointers cross each other. The index of the peak element will be returned.

Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the middle element is a peak), the time complexity is O(1).
Space Complexity: O(1) as we are using only a constant amount of extra space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start =0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if((mid==0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(mid>0 && nums[mid]<nums[mid-1]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1; 
    }
};