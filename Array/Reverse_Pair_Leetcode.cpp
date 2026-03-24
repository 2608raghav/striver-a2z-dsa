/*
Problem: Reverse Pairs
Platform: LeetCode
Topic: Array / Divide and Conquer

Approach:
1. Use a modified merge sort algorithm to count reverse pairs while sorting the array.
2. During the merge step, count the number of reverse pairs where nums[i] > 2 * nums[j].
3. Merge the two halves of the array while maintaining sorted order.

Time Complexity: O(n log n) since we are using merge sort.
Space Complexity: O(n) as we are using an additional vector for the merge step.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        // Count reverse pairs where nums[i] > 2 * nums[j]
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        // Merge the two sorted halves
        vector<int> temp;
        int i = left;
        j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        
        while (j <= right) {
            temp.push_back(nums[j++]);
        }
        
        // Copy back to original array
        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
        
        return count;
    }
    
    int mergeSortAndCount(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, left, mid) + 
                   mergeSortAndCount(nums, mid + 1, right);
        count += mergeAndCount(nums, left, mid, right);
        
        return count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }
};