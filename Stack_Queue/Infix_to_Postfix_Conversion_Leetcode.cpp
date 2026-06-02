/*
Problem: Infix to Postfix Conversion
Platform: Leetcode
Topic: Stack

Approach:
1. We can use a stack to hold operators and an output string to build the postfix expression.
2. We will iterate through each character in the infix expression:
   - If the character is an operand (number or variable), we will add it to the output string.
   - If the character is an operator, we will pop operators from the stack to the output string until we find an operator of lower precedence or a left parenthesis. Then we will push the current operator onto the stack.
   - If the character is a left parenthesis '(', we will push it onto the stack.
   - If the character is a right parenthesis ')', we will pop operators from the stack to the output string until we find a left parenthesis. We will discard the left parenthesis from the stack.
3. After processing all characters, we will pop any remaining operators from the stack to the output string.

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
    
    string infixToPostfix(string s) {
        stack<char> st;
        string result = "";
        
        for (char c : s) {
            if (isalnum(c)) {
                result += c; // Append operands to the output
            } else if (c == '(') {
                st.push(c); // Push '(' to stack
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top(); // Pop operators to output until '('
                    st.pop();
                }
                st.pop(); // Pop the '(' from stack
            } else { // Operator
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    result += st.top(); // Pop operators of higher or equal precedence
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
        
        return result;
    }
};