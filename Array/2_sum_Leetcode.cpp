/*
Problem: Two Sum
Platform: LeetCode
Topic: Array

Approach:
1. Create an unordered map (hash map) to store the value and its corresponding index from the input vector "nums".
2. Iterate through the input vector "nums" and for each element, calculate the complement (the value needed to reach the target) by subtracting the current element from the target.
3. Check if the complement exists in the map and ensure that it is not the same index as the current element (to avoid using the same element twice).
4. If the complement is found in the map, return the indices of the current element and the complement as a vector.

Time Complexity: O(n) since we need to iterate through the input vector once to populate the map and once to find the complement.
Space Complexity: O(n) as we are using an unordered map to store the elements and their indices.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;  // value -> index

        // store value and index in map
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int currValue = nums[i];
            int left = target - currValue;

            if (mp.find(left) != mp.end() && mp[left] != i) {
                res.push_back(i);
                res.push_back(mp[left]);
                break;   // pair found
            }
        }

        return res;
    }
};