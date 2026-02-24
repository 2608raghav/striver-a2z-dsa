/*
Problem: Reverse Integer
Platform: LeetCode
Topic: Basic Math
Approach: Extract digits and build reversed number while preventing overflow
Time Complexity: O(log10(|x|))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10; // for finding the last digit

            // Prevent overflow BEFORE it happens
            if (rev > INT_MAX/10 || rev < INT_MIN/10)
                return 0;

            rev = rev * 10 + digit; // build the reversed number
            x /= 10; // remove the last digit from x
        }

        return rev;
    }
};