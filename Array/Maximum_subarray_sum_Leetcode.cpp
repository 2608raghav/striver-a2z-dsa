/*
Problem: Maximum Subarray Sum
Platform: LeetCode
Topic: Array

Approach:
1. We can use Kadane's Algorithm to find the maximum subarray sum in linear time.
2. Initialize two variables, "mx" to store the maximum sum found so far and " sum" to store the current sum of the subarray being considered.
3. Iterate through the input vector "nums" and for each element:
   - Add the current element to "sum".
   - Update "mx" with the maximum of "mx" and "sum".
   - If "sum" becomes negative, reset it to 0 since a negative sum would not contribute to a maximum sum in future iterations.
4. After the loop, "mx" will contain the maximum subarray sum, which we return as the result.

Time Complexity: O(n) since we need to iterate through the input vector once to find the maximum subarray sum.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the current sum and the maximum sum.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long mx = INT_MIN;
        long long sum =0;
        long long a =0;
        // vector<int>res;
        int start = 0;
        int end =0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            if(sum>(mx)){
                mx = sum;
                end = i;
            }
            if(sum>=0){
                a = sum+a;
            }
            else{
                sum =0;
                start = i;
            }
        } 
        if(start>0){
            start++;
        }
        for(int i=start;i<=end;i++){
            cout<<nums[i]<<" ";
        }
        return mx;
    }
};