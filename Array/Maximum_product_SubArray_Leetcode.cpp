/*
Problem: Maximum Product Subarray
Platform: LeetCode
Topic: Array / Dynamic Programming

Approach:
1. Initialize three variables:
   - max_so_far to store maximum product ending at current index.
   - min_so_far to store minimum product ending at current index (needed because negative × negative = positive).
   - product_so_far to store the overall maximum product.
2. Start iterating from index 1 to n-1.
3. For each element:
   - Calculate possible maximum using:
        current element
        current element × previous max
        current element × previous min
   - Update max_so_far with maximum of these.
   - Update min_so_far with minimum of these.
   - Update product_so_far with maximum value seen so far.
4. Return product_so_far.

Key Idea:
Negative numbers can turn minimum product into maximum product,
so both max_so_far and min_so_far must be tracked.

Time Complexity: O(n)
- Single traversal of array.

Space Complexity: O(1)
- Only constant variables are used.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_so_far = nums[0];
        int max_so_far = nums[0];
        int product_so_far = nums[0];

        for(int i=1;i<nums.size();i++){
            int temp = max(nums[i],max(nums[i]*min_so_far,nums[i]*max_so_far));
            min_so_far = min(nums[i],min(nums[i]*min_so_far,nums[i]*max_so_far));
            max_so_far = temp;
            product_so_far = max(product_so_far,max_so_far);
        }
        
        return product_so_far;
    }
};
