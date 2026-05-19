/*
Problem: Combination Sum
Platform: LeetCode
Topic: Recursion

Approach:
1. We will use recursion to explore all possible combinations of the given candidates that sum up to the target.
2. We will define a helper function that takes the current index, the current combination being formed, and the remaining target sum.
3. The helper function will have two choices at each step: include the current candidate in the combination or exclude it. We will recursively call the helper function for both choices.

Time Complexity: O(2^n) in the worst case, where n is the number of candidates. This is because each candidate can either be included or excluded from the combination, leading to 2^n possible combinations.   
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findCombinations(vector<int>& candidates, int index, vector<int>& currentCombination, int target, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(currentCombination);
            return;
        }
        
        if (index == candidates.size() || target < 0) {
            return;
        }
        
        // Include the current candidate in the combination
        currentCombination.push_back(candidates[index]);
        findCombinations(candidates, index, currentCombination, target - candidates[index], ans);
        
        // Exclude the current candidate from the combination
        currentCombination.pop_back();
        findCombinations(candidates, index + 1, currentCombination, target, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currentCombination;
        findCombinations(candidates, 0, currentCombination, target, ans);
        return ans;
    }
};

