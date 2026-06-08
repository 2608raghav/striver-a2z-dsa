/*
Problem: Number of Greater Elements to the Right
Platform: GreeksforGeeks
Topic: Stack

Approach:
1. We can use a stack to keep track of the indices of the elements for which we are trying to find the number of greater elements to the right.
2. We will iterate through the array from right to left:
   - For each element, we will pop elements from the stack until we find an element that is greater than the current element or the stack becomes empty.
   - The number of popped elements will give us the count of greater elements to the right for the current element. We will store this in the result array.
   - Finally, we will push the current index onto the stack.

Time Complexity: O(n) where n is the length of the input array, since we will process each element once.
Space Complexity: O(n) in the worst case for the stack and the result array, if all elements are in decreasing order.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0); // Initialize result with 0
        stack<int> st; // Stack to hold indices
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop(); // Pop smaller or equal elements
            }
            result[i] = st.size(); // Number of greater elements to the right
            st.push(i); // Push current index onto stack
        }
        
        return result;
    }
};

