/*
Problem: Max Consecutive Ones III
Platform: LeetCode
Problem Number: 1004
Topic: Array, Sliding Window, Two Pointers

Approach:
1. Use two pointers:
      l = 0  -> Left boundary of the window
      r = 0  -> Right boundary of the window

2. Maintain a variable zeroes to count the number of
   zeroes present in the current window.

3. Expand the window by moving the right pointer r.

4. If nums[r] == 0:
      - Increment zeroes because a new zero enters
        the current window.

5. Check whether the number of zeroes exceeds k.

   If zeroes > k:
      - Check whether nums[l] == 0.
      - If yes, decrement zeroes.
      - Move the left pointer l forward.

6. If zeroes <= k:
      - The current window is valid.
      - Calculate its length:

            length = r - l + 1

      - Update the maximum length:

            max_len = max(max_len, length)

7. Continue until r reaches the end of the array.

8. Return max_len.

Time Complexity: O(n)
- Both left and right pointers traverse the array
  at most once.

Space Complexity: O(1)
- Only a few integer variables are used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0;
        int r = 0;

        int max_len = 0;
        int zeroes = 0;

        while (r < nums.size()) {

            // Count zeroes entering the window
            if (nums[r] == 0) {
                zeroes++;
            }

            // Shrink the window if zeroes exceed k
            if (zeroes > k) {

                // Remove the leftmost zero if present
                if (nums[l] == 0) {
                    zeroes--;
                }

                l++;
            }

            // Update maximum length for a valid window
            if (zeroes <= k) {
                max_len = max(max_len, r - l + 1);
            }

            // Expand the window
            r++;
        }

        return max_len;
    }
};