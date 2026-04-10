/*
Problem: Remove Outermost Parentheses
Platform: LeetCode
Topic: Strings

Approach:
1. We can use a stack to keep track of the parentheses.
2. We will iterate through the string and for each character:
   - If it is an opening parenthesis '(', we will push it onto the stack.
   - If it is a closing parenthesis ')', we will pop from the stack.
3. We will also keep track of the current depth of the parentheses using a counter.
4. If the depth is greater than 1, we will add the current character to the result string, as it is not an outermost parenthesis.

Time Complexity: O(n) since we are iterating through the string once.
Space Complexity: O(n) as we are using a stack to store the parentheses.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result = "";
        
        for(char c : s){
            if(c == '('){
                if(!st.empty()){
                    result += c; // Add to result if it's not an outermost parenthesis
                }
                st.push(c);
            }
            else{ // c == ')'
                st.pop();
                if(!st.empty()){
                    result += c; // Add to result if it's not an outermost parenthesis
                }
            }
        }
        return result;
    }
};