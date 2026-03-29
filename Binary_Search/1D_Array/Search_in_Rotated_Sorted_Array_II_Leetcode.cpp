/*
Problem: Search in Rotated Sorted Array II
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. If the element at the middle index is equal to the target, return true.
4. If the left half of the array is sorted (i.e., the element at the start index is less than or equal to the element at the middle index), check if the target is within the range of the left half. If it is, search in the left half; otherwise, search in the right half.
5. If the right half of the array is sorted (i.e., the element at the middle index is less than or equal to the element at the end index), check if the target is within the range of the right half. If it is, search in the right half; otherwise, search in the left half.
6. If the elements at the start index, middle index, and end index are equal, we cannot determine which half is sorted. In this case, we can simply move the start pointer one step to the right and the end pointer one step to the left to skip the duplicate elements.
7. Repeat steps 2-6 until the pointers cross each other.

Time Complexity: O(n) in the worst case when there are many duplicate elements, as we may have to check each element. In the average and best cases, the time complexity is O(log n) as we are dividing the search space in half at each step.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[start]<nums[mid]){
                if(target>=nums[start] && target<nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else if(nums[start]>nums[mid]){
                if(target>nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                start++;
            }
        }
        return false;
    }
};

