/*
Problem: Prefix to Infix Conversion
Platform: GreeksforGeeks
Topic: Stack

Approach:
1. We can use a stack to hold operands while processing the prefix expression from right to left.
2. We will iterate through each character in the prefix expression:
   - If the character is an operand (number or variable), we will push it onto the stack.
   - If the character is an operator, we will pop the top two operands from the stack, combine them with the operator in between, and push the resulting string back onto the stack.
3. After processing all characters, the stack will contain one element, which is the fully formed infix expression.

Time Complexity: O(n) where n is the length of the prefix expression, since we will process each character once.
Space Complexity: O(n) in the worst case for the stack, if all characters are operands.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string prefixToInfix(string s) {
        stack<string> st;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (isalnum(c)) {
                st.push(string(1, c)); // Push operands as strings
            } else { // Operator
                string op1 = st.top(); st.pop(); // First operand
                string op2 = st.top(); st.pop(); // Second operand
                string temp = "(" + op1 + c + op2 + ")"; // Combine with operator
                st.push(temp); // Push the resulting infix expression back to stack
            }
        }
        
        return st.top(); // The final infix expression
    }
};