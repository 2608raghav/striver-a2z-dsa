/*
Problem: Kadane's Algorithm
Platform: LeetCode
Topic: Array

Approach:
1. To find the maximum subarray sum using Kadane's Algorithm, we can initialize two variables: "max_sum" to store the maximum sum found so far and "current_sum" to store the sum of the current subarray being evaluated.
2. We can iterate through each element "num" in the input vector "nums".
3. For each element, we can update "current_sum" by taking the maximum of "num" and the sum of "current_sum" and "num". This step ensures that we either start a new subarray at the current element or continue the existing subarray.
4. We can then update "max_sum" by taking the maximum of "max_sum" and "current_sum". This step ensures that we keep track of the maximum sum found so far.
5. After iterating through the entire vector, "max_sum" will contain the maximum subarray sum. Return "max_sum".

Time Complexity: O(n) since we need to iterate through the input vector once to calculate the maximum subarray sum.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the "max_sum" and "current_sum" variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int current_sum = 0;
        
        for(int num : nums){
            current_sum = max(num, current_sum + num);
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};

