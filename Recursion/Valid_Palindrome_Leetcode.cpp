/*
Problem: Valid Palindrome
Platform: LeetCode
Topic: Recursion

Approach:
1. Create a new string that contains only alphanumeric characters from the input string, and convert them to lowercase.
2. Use two pointers, one starting at the beginning of the new string and the other at the end. Move both pointers towards the center, comparing characters at each step.
3. If any characters do not match, return false. If the pointers meet or cross each other without finding a mismatch, return true.


Time Complexity: O(n) where n is the length of the input string, since we are processing each character once to create the new string and then comparing characters in a single pass.
Space Complexity: O(n) for the new string that contains only alphanumeric characters, which in the worst case can be the same length as the input string if all characters are alphanumeric.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string res;

        for(char c : s) {
            if(isalnum(c)) {
                res.push_back(tolower(c));
            }
        }

        int left = 0;
        int right = res.size() - 1;

        while(left < right) {
            if(res[left] != res[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};