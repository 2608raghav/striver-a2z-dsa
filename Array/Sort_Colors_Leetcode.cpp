/*
Problem: Sort Colors
Platform: LeetCode
Topic: Array

Approach:
1. Initialize three pointers: "low" to 0, "mid" to 0, and "high" to the last index of the input vector "nums".
2. Use a while loop that continues until "mid" is less than or equal to "high".
3. Inside the loop, check the value at index "mid":
   - If it is 0, swap the values at indices "low" and "mid", then increment both "low" and "mid".
   - If it is 1, simply increment "mid".
   - If it is 2, swap the values at indices "mid" and "high", then decrement "high".
4. The loop will ensure that all 0s are moved to the beginning, all 1s are in the middle, and all 2s are moved to the end of the array.

Time Complexity: O(n) since we need to iterate through the input vector at most once to sort the colors.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the pointers and perform swaps.
*/

#include <bits/stdc++.h>
using namespace std;
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};