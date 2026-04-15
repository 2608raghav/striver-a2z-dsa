/*
Problem: String to Integer
Platform: LeetCode
Topic: Strings

Approach:
1. We can iterate through the string and ignore any leading whitespace characters.
2. We can check for an optional sign character ('+' or '-') and determine the sign of the resulting integer.
3. We can then iterate through the digits and construct the integer value while checking for overflow conditions.

Time Complexity: O(n) where n is the length of the string, as we need to iterate through the string once.
Space Complexity: O(1) since we are using a fixed amount of space for the result and the sign.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        
        return result * sign;
    }
};
