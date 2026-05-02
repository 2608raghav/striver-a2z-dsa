/*
Problem: Recursive Implementation of atoi
Platform: Leetcode
Topic: Recursion

Approach:
1. We will first skip any leading whitespace characters in the string.
2. We will then check for an optional sign character ('+' or '-') and determine the sign of the resulting integer.
3. We will then iterate through the characters of the string, converting them to digits and building the resulting integer. We will also check for overflow and underflow conditions during this process.

Time Complexity: O(n) since we may need to traverse the entire string once, where n is the length of the string.
Space Complexity: O(1) since we are using a constant amount of space to store the sign and the resulting integer.
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
       
