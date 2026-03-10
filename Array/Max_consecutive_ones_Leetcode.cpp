/*
Problem: Max Consecutive Ones
Platform: LeetCode
Topic: Array

Approach:
1. Initialize two variables, "count" and "res", to keep track of the current count of consecutive ones and the maximum count found so far, respectively.
2. Iterate through the input vector "nums" and for each element:
   - If the current element is 1, increment the "count" variable.
   - If the current element is not 1, update the "res" variable with the maximum of "count" and "res", and reset "count" to 0.
3. After the loop, update "res" one last time to account for the case where the array ends with a sequence of ones.
4. Finally, return the value of "res" which contains the maximum number of consecutive ones


Time Complexity: O(n) since we need to iterate through the input vector once to count the consecutive ones.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the count and the result.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int res =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
             res = max(count,res);
             count=0;
                
        }
        }
        res = max(count,res);
        return res;
    }
};