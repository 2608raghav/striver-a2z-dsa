/*
Problem: Subsets II
Platform: LeetCode
Topic: Recursion

Approach:
1. We will use recursion to explore all possible subsets of the given array and store them in a set to avoid duplicates.
2. We will define a helper function that takes the current index, the current subset being formed, and a set to store unique subsets.
3. The helper function will have two choices at each step: include the current element in the subset or exclude it. We will recursively call the helper function for both choices.
4. After exploring all subsets, we will convert the set of unique subsets into a vector and return it.

Time Complexity: O(2^n) in the worst case, where n is the number of elements in the array. This is because each element can either be included or excluded from the subset, leading to 2^n possible subsets.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case. Additionally, the space used to store the subsets can also be O(2^n) in the worst case if all subsets are unique.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findSubsets(vector<int>& nums, int index, vector<int>& currentSubset, set<vector<int>>& uniqueSubsets) {
        uniqueSubsets.insert(currentSubset);
        
        for (int i = index; i < nums.size(); i++) {
            // Include the current element in the subset
            currentSubset.push_back(nums[i]);
            findSubsets(nums, i + 1, currentSubset, uniqueSubsets);
            // Exclude the current element from the subset
            currentSubset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> uniqueSubsets;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        findSubsets(nums, 0, currentSubset, uniqueSubsets);
        
        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
    }
};
