/*
Problem: Power Set
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use recursion to generate the power set of a given set. The idea is to build the subsets character by character, ensuring that we explore both possibilities (including or excluding the current element).
2. We will define a helper function to recursively build the subsets.
3. The main function will call the helper function with the initial parameters.

Time Complexity: O(2^n) in the worst case, where n is the number of elements in the input set. This is because for each element, we have two choices (include or exclude), leading to 2^n possible subsets.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generatePowerSet(int index, vector<int>& current, vector<vector<int>>& result, vector<int>& nums) {
        result.push_back(current);
        
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            generatePowerSet(i + 1, current, result, nums);
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generatePowerSet(0, current, result, nums);
        return result;
    }
};
