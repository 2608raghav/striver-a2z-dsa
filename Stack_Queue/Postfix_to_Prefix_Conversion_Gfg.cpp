/*
Problem: Postfix to Prefix Conversion
Platform: GreeksforGeeks
Topic: Stack

Approach:
1. We can use a stack to hold operands and an output string to build the prefix expression.
2. We will iterate through each character in the postfix expression:
   - If the character is an operand (number or variable), we will push it onto the stack.
   - If the character is an operator, we will pop two operands from the stack, create a new expression with the operator followed by the two operands, and push this new expression back onto the stack.
3. After processing all characters, the final expression on the stack will be the prefix expression.

Time Complexity: O(n) where n is the length of the postfix expression, since we will process each character once.
Space Complexity: O(n) in the worst case for the stack, if all characters are operands.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string postfixToPrefix(string s) {
        stack<string> st;
        
        for (char c : s) {
            if (isalnum(c)) {
                st.push(string(1, c)); // Push operands as strings
            } else { // Operator
                string op2 = st.top(); st.pop(); // Second operand
                string op1 = st.top(); st.pop(); // First operand
                string temp = c + op1 + op2; // Combine with operator in prefix order
                st.push(temp); // Push the resulting prefix expression back to stack
            }
        }
        
        return st.top(); // The final prefix expression
    }
};