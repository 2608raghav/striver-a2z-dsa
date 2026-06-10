/*
Problem: Maximal Rectangle
Platform: Leetcode
Topic: Matrix, Stack, Dynamic Programming

Approach:
1. Treat each row of the matrix as the base of a histogram.
2. Maintain an array heights[] where:
   - heights[j] stores the number of consecutive '1's ending at the current row.
3. For every row:
   - If matrix[i][j] == '1', increment heights[j].
   - Otherwise, set heights[j] = 0.
4. After updating heights for the current row, solve the
   "Largest Rectangle in Histogram" problem on heights[].
5. The maximum rectangle found across all rows is the answer.

Time Complexity: O(m × n)
- For each row, we process the histogram in O(n).

Space Complexity: O(n)
- Extra space is used for the heights array and stack.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};