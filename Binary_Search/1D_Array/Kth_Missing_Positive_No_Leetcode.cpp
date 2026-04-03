/*
Problem: Kth Missing Positive Number
Platform: LeetCode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning of the array and one at the end of the array.
2. Calculate the middle index.
3. Calculate the number of missing positive numbers up to the middle index using the formula: missing = arr[mid] - (mid + 1).
4. If the number of missing positive numbers is less than k, it means the kth missing positive number is in the right half of the array. Therefore, update the left pointer to mid + 1.
5. If the number of missing positive numbers is greater than or equal to k, it means the kth missing positive number is in the left half of the array. Therefore, update the right pointer to mid.
6. Repeat steps 2-5 until the left pointer is greater than the right pointer.

Time Complexity: O(log n) where n is the length of the input array. The binary search takes O(log n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left + k;
    }
};