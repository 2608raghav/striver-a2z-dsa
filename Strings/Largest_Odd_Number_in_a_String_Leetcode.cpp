/*
Problem: Largest Odd Number in a String
Platform: LeetCode
Topic: Strings

Approach:
1. We can iterate through the string from the end to the beginning and check for the first odd digit.
2. If we find an odd digit, we can return the substring from the beginning of the string to that index (inclusive).

Time Complexity: O(n) since we are iterating through the string once.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--) {
            if((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
