/*
Problem: Rotate Array by k times
Platform: LeetCode
Topic: Array

Approach:
1. First, we need to reverse the last k elements of the array. This can be done by calling a helper function "reverse" that takes the array and the start and end indices as parameters.
2. Next, we reverse the first n-k elements of the array using the same "reverse" function.
3. Finally, we reverse the entire array to get the rotated array.

Time Complexity: O(n) since we need to reverse the array three times, and each reversal takes O(n) time.
Space Complexity: O(1) as we are performing the rotations in place without using any additional data structures.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void reverse(vector<int> &arr,int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
  }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
       
            k=k%n;
        
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
    }
};