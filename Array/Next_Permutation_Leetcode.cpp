/*
Problem: Next Permutation
Platform: LeetCode
Topic: Array

Approach:
1. Start from the end of the array and find the first pair of indices "ind" such that nums[ind] < nums[ind + 1]. If no such index exists, it means the array is in descending order, and we can simply reverse the entire array to get the next permutation.
2. If such an index "ind" is found, we need to find the smallest element to the right of "ind" that is greater than nums[ind]. We can do this by iterating from the end of the array until we find an element that is greater than nums[ind].
3. Once we find that element, we swap it with nums[ind].
4. Finally, we reverse the subarray to the right of "ind" to get the next permutation in place.

Time Complexity: O(n) since we may need to iterate through the array a few times (once to find the index "ind", once to find the element to swap, and once to reverse the subarray).
Space Complexity: O(1) as we are modifying the array in place and using only a constant amount of extra space for variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind =-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
             return;
        }
        for(int i=nums.size()-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
       
    }
};