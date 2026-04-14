/*
Problem: Maximum Nesting Depth of Parentheses
Platform: LeetCode
Topic: Strings

Approach:
1. We can use a stack to keep track of the opening parentheses.
2. We can iterate through the string and for every opening parenthesis, we push it onto the stack and update the maximum depth.
3. For every closing parenthesis, we pop from the stack.

Time Complexity: O(n) where n is the length of the string, as we need to iterate through the string once.
Space Complexity: O(n) in the worst case when all characters are opening parentheses, as we need to store them in the stack.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = 0;
        
        for(char c : s) {
            if(c == '(') {
                st.push(c);
                maxDepth = max(maxDepth, (int)st.size());
            } else if(c == ')') {
                if(!st.empty()) {
                    st.pop();
                }
            }
        }
        
        return maxDepth;
    }
};