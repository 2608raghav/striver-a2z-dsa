/*
Problem: Roman to Integer
Platform: LeetCode
Topic: Strings

Approach:
1. We can create a mapping of Roman numerals to their integer values.
2. We can iterate through the string and for each character, we can check if the next character has a higher value than the current character. If it does, we subtract the current value from the total; otherwise, we add it to the total.

Time Complexity: O(n) where n is the length of the string, as we need to iterate through the string once.
Space Complexity: O(1) since we are using a fixed amount of space for the mapping and the result.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && romanMap[s[i]] < romanMap[s[i + 1]]) {
                total -= romanMap[s[i]];
            } else {
                total += romanMap[s[i]];
            }
        }
        
        return total;
    }
};
