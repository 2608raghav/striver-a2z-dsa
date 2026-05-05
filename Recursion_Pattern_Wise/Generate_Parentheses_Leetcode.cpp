/*
Problem: Generate Parentheses
Platform: Leetcode
Topic: Recursion

Approach:
1. We will use recursion to generate all combinations of well-formed parentheses. The idea is to build the string character by character, ensuring that we never place more closing parentheses than opening parentheses at any point.
2. We will define a helper function to recursively build the parentheses string.
3. The main function will call the helper function with the initial parameters.

Time Complexity: O(4^n / sqrt(n)) in the worst case, where n is the number of pairs of parentheses. This is because the number of valid combinations of parentheses is given by the nth Catalan number, which grows asymptotically as O(4^n / sqrt(n)).
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generateParenthesis(int n, string current, vector<string>& result, int openCount, int closeCount) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Add '(' if we still have opening parentheses left
        if (openCount < n) {
            generateParenthesis(n, current + '(', result, openCount + 1, closeCount);
        }
        
        // Add ')' if we have more opening parentheses than closing parentheses
        if (closeCount < openCount) {
            generateParenthesis(n, current + ')', result, openCount, closeCount + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(n, "", result, 0, 0);
        return result;
    }
};