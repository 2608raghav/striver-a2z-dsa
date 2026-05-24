/*
Problem: Expression Add Operators
Platform: Leetcode
Topic: Recursion

Approach:
1. We will use backtracking to generate all possible combinations of the input string by inserting the operators '+', '-', and '*' between the digits.
2. We will define a helper function that takes the current expression, the position in the input string, the current evaluated value of the expression, and the last operand used (to handle multiplication).
3. The helper function will iterate through the input string starting from the current position and try to form numbers by concatenating digits. For each number formed, we will recursively call the helper function with the updated expression and evaluated value based on the operator used.
4. We will handle the operator precedence for multiplication by keeping track of the last operand used and adjusting the evaluated value accordingly when we encounter a multiplication operator.   
5. If we reach the end of the input string and the evaluated value matches the target, we will add the current expression to the result list.

Time Complexity: O(4^n) in the worst case, where n is the length of the input string. This is because for each digit, we have 4 choices (no operator, '+', '-', '*').
Space Complexity: O(n) due to the recursive call stack and the space used to store the current expression.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(result, num, target, "", 0, 0, 0);
        return result;
    }   
private:    void backtrack(vector<string>& result, const string& num, int target, string expression, int pos, long long evaluated, long long lastOperand) {
        if (pos == num.size()) {
            if (evaluated == target) {
                result.push_back(expression);
            }
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (i != pos && num[pos] == '0') { // Skip numbers with leading zero
                break;
            }
            long long currentOperand = stoll(num.substr(pos, i - pos + 1));
            if (pos == 0) {
                backtrack(result, num, target, expression + to_string(currentOperand), i + 1, currentOperand, currentOperand);
            } else {
                backtrack(result, num, target, expression + "+" + to_string(currentOperand), i + 1, evaluated + currentOperand, currentOperand);
                backtrack(result, num, target, expression + "-" + to_string(currentOperand), i + 1, evaluated - currentOperand, -currentOperand);
                backtrack(result, num, target, expression + "*" + to_string(currentOperand), i + 1, evaluated - lastOperand + lastOperand * currentOperand, lastOperand * currentOperand);
            }
        }
    }
};
