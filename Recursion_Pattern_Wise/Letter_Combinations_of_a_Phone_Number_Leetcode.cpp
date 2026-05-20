/*
Problem: Letter Combinations of a Phone Number
Platform: Leetcode
Topic: Recursion

Approach:
1. We will use recursion to generate all possible letter combinations for the given digit string based on the mapping of digits to letters on a phone keypad.
2. We will define a helper function that takes the current index in the digit string, the current combination being formed, and a vector to store the results.
3. The helper function will iterate through the possible letters for the current digit and recursively call itself to build the combinations until we reach the end of the digit string.
4. The main function will call the helper function with the initial parameters.

Time Complexity: O(4^n) in the worst case, where n is the length of the input digit string. This is because each digit can map to up to 4 letters (e.g., '7' and '9'), leading to a maximum of 4^n combinations.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case. Additionally, the space used to store the combinations can also be O(4^n) in the worst case if all combinations are unique.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(const string& digits, int index, string current, vector<string>& result, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (char letter : mapping[digit]) {
            backtrack(digits, index + 1, current + letter, result, mapping);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        backtrack(digits, 0, "", result, mapping);
        
        return result;
    }
};


