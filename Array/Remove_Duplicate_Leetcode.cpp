/*
Problem: Remove Duplicates from Sorted Array
Platform: LeetCode
Topic: Array

Approach:
1. Create an empty vector "y" to store the unique elements.
2. Check if the input vector "nums" is empty. If it is, return 0.
3. If the size of "nums" is 1, return the single element as it is the only unique element.
4. Initialize two pointers, "l" and "k", to 0. "l" will be used to traverse the input vector, and "k" will keep track of the number of unique elements found.
5. Use a while loop to iterate through the input vector until "l" reaches the second
last element.
   - If the current element at index "l" is not equal to the next element at index "l+1", it means we have found a unique element. Push this element into vector "y", increment "k" and move the pointer "l" to the next position.
   - If the current element is equal to the next element, simply move the pointer "l" to the next position without adding it to vector "y".

Time Complexity: O(n) since we need to iterate through the input vector once to find the unique elements.
Space Complexity: O(n) as we are using an additional vector "y" to store the unique elements. However, if we modify the input vector in place, we can achieve O(1) space complexity.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         vector<int> y;
    if(nums.size()==0){
        return 0;
    }
    if(nums.size()==1){
        return(nums[0]);
    }
   
    int l =0;
    int k=0;
    while(l<nums.size()-1){
        if(nums[l]!=nums[l+1]){
            y.push_back(nums[l]);
            k++;
            l++;
        }
        else{
            l++;
        }
        if(l==nums.size()-1){
            y.push_back(nums[l]);
            k++;
        }
    }
    nums=y;
    return y.size();
    }
};