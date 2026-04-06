/*
Problem: Split Array Largest Sum
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the maximum element in the array (the minimum possible largest sum) and one at the sum of all elements in the array (the maximum possible largest sum).
2. Calculate the middle largest sum.
3. Calculate the number of subarrays needed to split the array such that the largest sum of any subarray is less than or equal to the middle largest sum.
4. If the number of subarrays needed is less than or equal to the given number of subarrays (m), it means we can split the array with the middle largest sum or a smaller largest sum. Therefore, update the end pointer to mid.
5. If the number of subarrays needed is greater than the given number of subarrays (m), it means we need to split the array with a larger largest sum. Therefore, update the start pointer to mid + 1.
6. Repeat steps 2-5 until the start pointer is equal to the end pointer.

Time Complexity: O(n log m) where n is the number of elements in the array and m is the range of possible largest sums (from the maximum element in the array to the sum of all elements in the array). The binary search takes O(log m) time and calculating the number of subarrays takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);
        while(start<end){
            int mid = (start+end)/2;
            long long sum = 0;
            int count = 1; // Start with one subarray
            for(int num:nums){
                sum+=num;
                if(sum>mid){
                    count++; // Need to start a new subarray
                    sum=num; // Reset sum to the current number
                }
            }
            if(count<=m){
                end=mid; // We can try for a smaller largest sum
            }
            else{
                start=mid+1; // We need a larger largest sum
            }
        }
        return start; // or end, both are the same at this point
    }
};