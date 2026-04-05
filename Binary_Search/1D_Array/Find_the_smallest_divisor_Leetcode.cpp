/*
Problem: Find the smallest divisor
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the minimum element in the array and one at the maximum element in the array.
2. Calculate the middle divisor.
3. Calculate the sum of the division of each element in the array by the middle divisor, rounding up to the nearest integer.
4. If the sum is less than or equal to the threshold, it means we can use the middle divisor or a smaller divisor. Therefore, update the end pointer to mid.
5. If the sum is greater than the threshold, it means we need to use a larger divisor. Therefore, update the start pointer to mid + 1.
6. Repeat steps 2-5 until the start pointer is equal to the end pointer. The value at the start (or end) pointer will be the smallest divisor that satisfies the condition.

Time Complexity: O(n log m) where n is the number of elements in the array and m is the range of possible divisors (from 1 to the maximum element in the array). The binary search takes O(log m) time and calculating the sum takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        while(start<end){
            int mid = (start+end)/2;
            long long sum = 0;
            for(int num:nums){
                sum+= (num+mid-1)/mid; // this is a trick to round up the division
            }
            if(sum<=threshold){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};

