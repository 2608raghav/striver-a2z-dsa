/*
Problem: Palindrome Number
Platform: LeetCode
Topic: Basic Math
Approach: 1. Negative numbers are not palindromes.
          2. Extract digits and compare with the reversed number.   
          
Time Complexity: O(log10(n)) where n is the input number, since we are processing each digit once.
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }

        int original = x; // Store the original number
        int reversed = 0;

        while (x > 0) {
            int digit = x % 10; // Get the last digit

            // Check for potential overflow before it happens
            if (reversed > (INT_MAX - digit) / 10) {
                return false; // If overflow would occur, it's not a palindrome
            }

            reversed = reversed * 10 + digit; // Build the reversed number
            x /= 10; // Remove the last digit from x
        }

        return original == reversed; // Check if original and reversed are the same
    }
};