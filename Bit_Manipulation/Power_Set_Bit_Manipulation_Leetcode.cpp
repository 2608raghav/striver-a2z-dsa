/*
Problem: Power Set
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. The power set of a set is the set of all possible subsets of that set. For a set of size n, there are 2^n subsets in the power set.
2. We can use bit manipulation to generate all subsets. Each subset can be represented by a binary number where the i-th bit indicates whether the i-th element of the original set is included in the subset.
3. We can iterate from 0 to 2^n - 1, and for each number, we can determine which elements are included in the corresponding subset by checking the bits of the number.

Time Complexity: O(n * 2^n) where n is the number of elements in the original set, since we need to generate 2^n subsets and each subset can take up to O(n) time to construct.
Space Complexity: O(n * 2^n) since we are storing all the subsets in the result vector, and each subset can take up to O(n) space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // Iterate from 0 to 2^n - 1
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            // Check each bit of the current number
            for (int j = 0; j < n; j++) {
                // If the j-th bit is set, include the j-th element in the subset
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};
   
