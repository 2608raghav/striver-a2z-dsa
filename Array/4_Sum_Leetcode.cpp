/*
Problem: 4 Sum
Platform: LeetCode
Topic: Array

Approach:
1. We first check if the size of the input vector "nums" is less than 4. If it is, we return an empty result vector since we cannot form a quadruplet.
2. We sort the input vector "nums" in ascending order. Sorting helps us to easily identify and skip duplicate elements, and also allows us to use the two-pointer technique to find pairs that sum up to a specific value.
3. We initialize an empty vector of vectors "result" to store the resulting quadruplets that sum up to the target.
4. We iterate through the sorted vector "nums" using two nested loops. The outer loop runs from the first element to the fourth last element, and the inner loop runs from the second element to the third last element. For each pair of indices "i" and "j":
   - If "i" is greater than 0 and the current element is the same as the previous element, we skip it to avoid duplicates.
   - If "j" is greater than "i + 1" and the current element is the same as the previous element, we skip it to avoid duplicates.
   - We then initialize two pointers, "left" and "right", to find pairs that sum up to the target minus the sum of the elements at indices "i" and "j".
   - We use a while loop to move the "left" and "right" pointers towards each other:
     - If the sum of the elements at "i", "j", "left", and "right" is less than the target, we move the "left" pointer rightward to increase the sum.
     - If the sum is greater than the target, we move the "right" pointer leftward to decrease the sum.
     - If the sum is equal to the target, we have found a valid quadruplet. We add this quadruplet to the result vector "result". We then move both pointers inward and skip any duplicate elements to avoid repeating the same quadruplet.
5. After the loops, we return the result vector "result" which contains all the unique quadruplets that sum up to the target.


Time Complexity: O(n^3) since we have two nested loops and the two-pointer technique inside the innermost loop.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the pointers and result vector (excluding the space used for the output).

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] 
                                    + nums[left] + nums[right];

                    if (sum < target) {
                        left++;
                    } 
                    else if (sum > target) {
                        right--;
                    } 
                    else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                }
            }
        }

        return result;
    }
};