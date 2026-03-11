/*
Problem: Finding the number that appears twice
Platform: LeetCode
Topic: Array

Approach:
1. Initialize a variable "ans" to 0. This variable will be used to store the result of XOR operations.
2. Iterate through each number "num" in the input vector "nums".
3. For each number, perform an XOR operation between "ans" and "num" and update "ans" with the result. The XOR operation will cancel out all numbers that appear once, leaving only the number that appears twice.
4. After iterating through the entire vector, "ans" will contain the number that appears twice. Return "ans".


Time Complexity: O(n) since we need to iterate through the input vector once to perform the XOR operations.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the "ans" variable.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int num : nums){
            ans ^= num;
        }
        
        return ans;
    }
};