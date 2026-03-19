/*
Problem: 3 Sum
Platform: LeetCode
Topic: Array

Approach:
1. We first sort the input vector "nums" in ascending order. Sorting helps us to easily identify and skip duplicate elements, and also allows us to use the two-pointer technique to find pairs that sum up to a specific value.
2. We initialize an empty vector of vectors "res" to store the resulting triplets that sum up to zero.
3. We iterate through the sorted vector "nums" from the first element to the third last element. For each element at index "i":
   - If it is the same as the previous element (to avoid duplicates), we skip it.
   - We then initialize two pointers, "start" and "end", to find pairs that sum up to the negative of the current element (i.e., -nums[i]).
   - We use a while loop to move the "start" and "end" pointers towards each other:
     - If the sum of the elements at "start", "end", and "i" is zero, we have found a valid triplet. We add this triplet to the result vector "res". We then move both pointers inward and skip any duplicate elements to avoid repeating the same triplet.
     - If the sum is greater than zero, it means we need a smaller number, so we move the "end" pointer leftward.
     - If the sum is less than zero, it means we need a larger number, so we move the "start" pointer rightward.
4. After the loop, we return the result vector "res" which contains all the unique triplets that sum up to zero.

Time Complexity: O(n^2) since we need to iterate through the input vector and use the two-pointer technique.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the pointers and result vector.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int n = nums.size();
         vector<vector<int>>res;
         for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
            int start = i+1;
            int end = n-1;
            
            while(start<end){
                
                if(nums[start]+nums[end]+nums[i]==0){
                    vector<int>temp = {nums[i],nums[start],nums[end]};
                    res.push_back(temp);
                    start++;
                    end--;
                    while(start<end && nums[start]==nums[start-1]){
                        start++;
                    }
                    while(start<end && nums[end]==nums[end+1]){
                        end--;
                    }
                    
                }
                else if(nums[start]+nums[end]+nums[i]>0){
                    end--;
                }
                else{
                    start++;
                }
            }
            
            }
         return res;
    }
};