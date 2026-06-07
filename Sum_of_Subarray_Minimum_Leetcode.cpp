/*
Problem: Sum of Subarray Minimums
Platform: LeetCode
Topic: Monotonic Stack

Approach:
1. For each element, determine:
   - Previous Smaller Element (PSE)
   - Next Smaller Element (NSE)
2. Use monotonic increasing stacks to efficiently find these indices.
3. Calculate the number of subarrays where the current element acts as the minimum:
   - Left choices = i - PSE[i]
   - Right choices = NSE[i] - i
4. Contribution of each element:
   - arr[i] * Left choices * Right choices
5. Sum all contributions and return the result modulo 1e9+7.

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> pse(n), nse(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans = (ans + ((long long)arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return (int)ans;
    }
};
