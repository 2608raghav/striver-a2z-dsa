/*
Problem: Trapping Rain Water
Platform: LeetCode
Topic: Two Pointers, Array

Approach:
1. Use two pointers, one at the beginning (left) and one at the end (right) of the array.
2. Maintain the maximum height seen so far from both sides:
   - leftMax stores the tallest bar encountered from the left.
   - rightMax stores the tallest bar encountered from the right.
3. Move the pointer with the smaller height:
   - If height[left] < height[right]:
     - Update leftMax if needed.
     - Otherwise, water trapped = leftMax - height[left].
     - Move left pointer forward.
   - Else:
     - Update rightMax if needed.
     - Otherwise, water trapped = rightMax - height[right].
     - Move right pointer backward.
4. Continue until both pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
};
