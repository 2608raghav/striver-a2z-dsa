/*
Problem: Majority Element
Platform: LeetCode
Topic: Array

Approach:
1. We can use the Boyer-Moore Voting Algorithm to find the majority element in linear time and constant space.
2. Initialize two variables: "count" to keep track of the count of the current candidate and "candidate" to store the current candidate for the majority element.
3. Iterate through the input vector "nums":
    - If "count" is 0, update "candidate" to the current element and set "count" to 1.
    - If the current element is equal to "candidate", increment "count".
    - Otherwise, decrement "count".
4. After the first pass, "candidate
" will hold the majority element. However, we need to verify that it is indeed the majority element by counting its occurrences in a second pass.
5. If the count of "candidate" is greater than n/2, return "candidate
". Otherwise, return -1 (or any value indicating that there is no majority element).


Time Complexity: O(n) since we need to iterate through the input vector twice (once to find the candidate and once to verify it).
Space Complexity: O(1) as we are using only a constant amount of extra space to store the count and candidate variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int candidate =0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate = nums[i];
                count =1;

            }
            else if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        int n = nums.size();
        count =0;
        for(int i:nums){
            if(i==candidate){
                count++;
            }
        }
        if(count>n/2){
            return candidate;
        }
        return -1;
    }
};
