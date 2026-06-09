/*
Problem: Sum of Subarray Ranges
Platform: Leetcode
Topic: Arrays, Monotonic Stack

Approach:
1. The range of a subarray is defined as:
      Range = Maximum Element - Minimum Element
2. Instead of generating all subarrays, we calculate:
      Sum of all subarray maximums
      - Sum of all subarray minimums
3. For each element, determine:
      - How many subarrays consider it as the maximum.
      - How many subarrays consider it as the minimum.
4. Use monotonic stacks to find:
      - Previous Greater Element (PGE)
      - Next Greater Element (NGE)
      - Previous Smaller Element (PSE)
      - Next Smaller Element (NSE)
5. The contribution of an element as maximum:
      nums[i] × leftCount × rightCount
6. The contribution of an element as minimum:
      nums[i] × leftCount × rightCount
7. Sum all maximum contributions and minimum contributions separately.
8. Return:
      Total Maximum Contribution - Total Minimum Contribution

Time Complexity: O(n)
- Each element is pushed and popped from the stack at most once.

Space Complexity: O(n)
- Extra space is used for stacks and helper arrays.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<long long> leftMin(n), rightMin(n);
        vector<long long> leftMax(n), rightMax(n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            leftMin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            rightMin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            rightMax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long maxSum = 0;
        long long minSum = 0;

        for (int i = 0; i < n; i++) {
            maxSum += (long long)nums[i] * leftMax[i] * rightMax[i];
            minSum += (long long)nums[i] * leftMin[i] * rightMin[i];
        }

        return maxSum - minSum;
    }
};