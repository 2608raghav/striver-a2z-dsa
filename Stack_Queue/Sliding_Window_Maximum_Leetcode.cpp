/*
Problem: Sliding Window Maximum
Platform: Leetcode
Topic: Array, Queue, Monotonic Queue

Approach:
1. Use a deque to store indices of elements in decreasing order of their values.
2. For each element:
   - Remove indices from the front if they are outside the current window.
   - Remove indices from the back while the current element is greater than
     or equal to the elements represented by those indices.
3. Add the current index to the deque.
4. Once the first window of size k is formed:
   - The front of the deque contains the index of the maximum element.
   - Add that value to the answer.
5. Continue this process for all windows.

Time Complexity: O(n)
- Each element is inserted and removed from the deque at most once.

Space Complexity: O(k)
- The deque stores at most k indices.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};