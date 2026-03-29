/*
Problem: Search in Rotated Sorted Array I
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. If the element at the middle index is equal to the target, return the middle index
4. If the left half of the array is sorted (i.e., the element at the start index is less than or equal to the element at the middle index), check if the target is within the range of the left half. If it is, search in the left half; otherwise, search in the right half.
5. If the right half of the array is sorted (i.e., the element at the middle index is less than or equal to the element at the end index), check if the target is within the range of the right half. If it is, search in the right half; otherwise, search in the left half.
6. Repeat steps 2-5 until the pointers cross each other.

Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the target is found at the middle index), the time complexity is O(1).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[start]<=nums[mid]){
                if(target>=nums[start] && target<nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(target>nums[mid] && target<=nums[end]){
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
