/*
Problem: Balanced Parentheses
Platform: Leetcode
Topic: Recursion

Approach:
1. We can use a recursive backtracking approach to generate all possible combinations of parentheses.
2. We will maintain two counts: one for the number of opening parentheses used and one for the number of closing parentheses used.
3. We will start with an empty string and at each step, we can either add an opening parenthesis (if we have not used all of them) or a closing parenthesis (if it does not exceed the number of opening parentheses used).
4. We will continue this process until we have used all opening and closing parentheses, at which point we will add the generated string to our result list.

Time Complexity: O(4^n / sqrt(n)) in the worst case, where n is the number of pairs of parentheses. This is because there are C(n) = (2n)! / ((n + 1)! * n!) valid combinations of parentheses, which is approximately O(4^n / sqrt(n)).
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case, and O(4^n / sqrt(n)) for storing the valid combinations in the result list.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generateParenthesisHelper(int open, int close, string current, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        
        if (open > 0) {
            generateParenthesisHelper(open - 1, close, current + "(", result);
        }
        if (close > open) {
            generateParenthesisHelper(open, close - 1, current + ")", result);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(n, n, "", result);
        return result;
    }
};
