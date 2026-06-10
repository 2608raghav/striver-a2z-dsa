/*
Problem: Largest Rectangle in Histogram
Platform: Leetcode
Topic: Stack, Monotonic Stack

Approach:
1. For each bar, find:
   - Previous Smaller Element (PSE)
   - Next Smaller Element (NSE)
2. The width of the largest rectangle that can be formed using the current
   bar as the minimum height is:
      width = NSE - PSE - 1
3. The area contributed by the current bar is:
      area = height[i] * width
4. Use a monotonic increasing stack to efficiently find the previous and next
   smaller elements.
5. Compute the area for every bar and keep track of the maximum area.

Time Complexity: O(n)
- Each element is pushed and popped from the stack at most once.

Space Complexity: O(n)
- Extra space is used for the stack.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                  (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};