/*
Problem: Rearrange Array Elements by Sign
Platform: LeetCode
Topic: Array

Approach:
1. Create two separate vectors, "even" and "odd", to store the positive and negative numbers from the input vector "nums", respectively.
2. Iterate through the input vector "nums" in reverse order and populate the "even" vector with positive numbers and the "odd" vector with negative numbers.
3. After populating the "even" and "odd" vectors, iterate through the input vector "nums" again and fill the even indices with elements from the "even" vector and the odd indices with elements from the "odd" vector.
4. Finally, return the modified input vector "nums" which now contains the rearranged elements


Time Complexity: O(n) since we need to iterate through the input vector a few times (once to separate the positive and negative numbers, and once to rearrange them).
Space Complexity: O(n) as we are using additional space to store the "even" and "odd" vectors.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>even;
        vector<int>odd;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>0){
               even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i] = even.back();
                even.pop_back();
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i%2!=0){
                nums[i] = odd.back();
                odd.pop_back();
            }
        }
        return nums;
    }
};