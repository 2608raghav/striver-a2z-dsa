/*
Problem: Next Greater Element-2
Platform: Leetcode
Topic: Stack

Approach:
1. We can use a stack to keep track of the indices of the elements for which we are trying to find the next greater element.
2. Since the array is circular, we will iterate through the array twice (from right to left):
   - For each element, we will pop elements from the stack until we find an element that is greater than the current element or the stack becomes empty.
   - If the stack is not empty after popping, the top of the stack will be the next greater element for the current element. We will store this in the result array.
   - If the stack is empty, it means there is no greater element to the right, so we will store -1 in the result array.
   - Finally, we will push the current index onto the stack.
   

Time Complexity: O(n) where n is the length of the input array, since we will process each element at most twice.
Space Complexity: O(n) in the worst case for the stack and the result array, if all elements are in decreasing order.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize result with -1
        stack<int> st; // Stack to hold indices
        
        for (int i = 2 * n - 1; i >= 0; i--) {
            int currentIndex = i % n; // Get the actual index in the circular array
            while (!st.empty() && nums[st.top()] <= nums[currentIndex]) {
                st.pop(); // Pop smaller or equal elements
            }
            if (!st.empty()) {
                result[currentIndex] = nums[st.top()]; // Next greater element
            }
            st.push(currentIndex); // Push current index onto stack
        }
        
        return result;
    }
};