/*
Problem: Count Subarray with sum k
Platform: LeetCode
Topic: Array

Approach:
1. Initialize a variable "count" to 0. This variable will be used to store the result.
2. Use a HashMap to store the frequency of prefix sums.
3. Iterate through the input array and calculate the prefix sum.
4. Check if (prefix_sum - k) exists in the HashMap. If it does, increment the count by the frequency of that sum.
5. Update the HashMap with the current prefix sum and its frequency.
6. Return the count.

Time Complexity: O(n) since we need to iterate through the input array once to calculate the prefix sums and update the HashMap.
Space Complexity: O(n) in the worst case if all prefix sums are unique and stored in the HashMap.
*/

#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int count = 0;
        int sum = 0;

        mp[0] = 1;  // Important base case

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int left = sum - k;

            if (mp.find(left) != mp.end()) {
                count += mp[left];
            }

            mp[sum]++;
        }

        return count;
    }
};