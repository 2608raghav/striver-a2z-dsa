/*
Problem: Infix to Prefix Conversion
Platform: GreeksforGeeks
Topic: Stack

Approach:
1. We can reverse the infix expression and then apply a similar logic to infix to postfix conversion, but with some modifications:
   - When we encounter an operator, we will pop operators from the stack to the output string until we find an operator of lower precedence or a right parenthesis. Then we will push the current operator onto the stack.
   - When we encounter a left parenthesis '(', we will pop operators from the stack to the output string until we find a right parenthesis. We will discard the right parenthesis from the stack.
   - When we encounter a right parenthesis ')', we will push it onto the stack.
2. After processing all characters, we will pop any remaining operators from the stack to the output string.
3. Finally, we will reverse the output string to get the prefix expression.


Time Complexity: O(n) where n is the length of the infix expression, since we will process each character once.
Space Complexity: O(n) in the worst case for the output string and the stack, if all characters are operators or parentheses.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    
    string infixToPrefix(string s) {
        stack<char> st;
        string result = "";
        
        // Reverse the infix expression
        reverse(s.begin(), s.end());
        
        for (char c : s) {
            if (isalnum(c)) {
                result += c; // Append operands to the output
            } else if (c == ')') {
                st.push(c); // Push ')' to stack
            } else if (c == '(') {
                while (!st.empty() && st.top() != ')') {
                    result += st.top(); // Pop operators to output until ')'
                    st.pop();
                }
                st.pop(); // Pop the ')' from stack
            } else { // Operator
                while (!st.empty() && precedence(st.top()) > precedence(c)) {
                    result += st.top(); // Pop operators of higher precedence
                    st.pop();
                }
                st.push(c); // Push current operator to stack
            }
        }
        
        // Pop any remaining operators from the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // Reverse the result to get the prefix expression
        reverse(result.begin(), result.end());
        
        return result;
    }
};  

